#include <string.h>
#include "API/dataTypes.h"
#include "mmu.h"

asm("\t .bss _taskMasterTableAddress, 4\n" \
    "\t .bss _globalVariable, 4\n" \
    "\t .global _taskMasterTableAddress\n" \
    "\t .global _globalVariable\n" \
    "taskMasterTableAddress .field _taskMasterTableAddress, 32\n" \
    "globalVariable .field _globalVariable, 32\n");
extern address taskMasterTableAddress;
extern unsigned int globalVariable;
extern volatile unsigned int kernelMasterTable;
extern volatile unsigned int intRamStart;
extern volatile unsigned int extDDRStart;

MMU MMU::INSTANCE = MMU();

MMU::MMU() {
    int max = 0;
    if (MAX_PAGES_IN_EXT_DDR > MAX_PAGES_IN_INT_RAM) {
        max = MAX_PAGES_IN_EXT_DDR;
    } else {
        max = MAX_PAGES_IN_INT_RAM;
    }
    if (MAX_MMU_TABLES > max) {
        max = MAX_MMU_TABLES;
    }
    for (int i = 0; i < max; i++) {
        if (i < MAX_PAGES_IN_EXT_DDR) {
            m_occupiedPagesExtDDR[i] = false;
        }
        if (i < MAX_PAGES_IN_INT_RAM) {
            m_occupiedPagesIntRam[i] = false;
        }
        if (i < MAX_MMU_TABLES) {
            m_taskMasterTableAddresses[i] = 0x0;
        }
    } 

}

MMU::~MMU() {
}

MMU* MMU::getInstance() {
    return &INSTANCE;
}

void MMU::enableMMU() {
    asm("\t MRC p15, #0, r0, c1, c0, #0\n");
    asm("\t ORR r0, r0, #0x1\n");
    asm("\t MCR p15, #0, r0, c1, c0, #0\n");
}

void MMU::initDomainAccess() {
    // Set Domain Access control register to 0101 0101 0101 0101 0101 0101 0101 0111 
    asm("\t MOV  r0, #0x5557\n");
    asm("\t MOVT r0, #0x5555\n");
    asm("\t MCR  p15, #0, r0, c3, c0, #0\n");
}

void MMU::clearTLB() {
    asm("\t MOV r0, #0x0\n");
    asm("\t MCR p15, #0, r0, c8, c7, #0\n");
}

void MMU::lockFirstTLBEntry() {
    globalVariable = EXT_DDR_START;
    asm("\t LDR  r1, globalVariable\n");
    asm("\t LDR r1, [r1]\n");
    asm("\t MOV  r0, #0x1\n"); //base=victim=0 (protect bit=1 [lock])
    asm("\t MOV  r2, #0x0000\n");//base=victim=1 (protect bit=0 [unlock])
    asm("\t MOVT r2, #0x0840\n");
    asm("\t MCR  p15, #0, r0, c10, c0, #1\n"); //Write I-TLB Lockdown Register
    asm("\t MCR  p15, #0, r1, c10, c1, #1\n"); //Prefetch I-TLB
    asm("\t MCR  p15, #0, r2, c10, c0, #1\n"); //Write I-TLB Lockdown Register
}

void MMU::setMasterTablePointerTo(address tableAddress) {
    taskMasterTableAddress = tableAddress;
    unsigned int tempAddress = (unsigned int)taskMasterTableAddress & 0xFFFFC000;
    taskMasterTableAddress = (address)tempAddress;
    
    asm("\t LDR r1, taskMasterTableAddress\n");
    asm("\t LDR r1, [r1]\n");
    asm("\t MCR p15, #0, r1, c2, c0, #0\n");
    
    clearTLB();
}

void MMU::mapOneToOne(address masterTableAddress, unsigned int startAddress, unsigned int length) {
    int nrOfMasterTableEntries = (length / 1048576) + 1;
    
    int firstEntryNumber = (startAddress >> 12) - ((startAddress >> 12) & 0xFFF00);
    int lastEntryNumber = firstEntryNumber + (length / 4096);
    
    unsigned int firstL2Entry = (startAddress >> 20) << 20;
    for (int i = 0; i < nrOfMasterTableEntries; i++) {
        unsigned int masterTableEntryNumber = startAddress >> 20;
        address freeForL2Table = 0x0;
        if (*(masterTableAddress + masterTableEntryNumber) == 0x0) {
            if (i % 4 == 0) { // 4 L2 tables fit into one 4KB page
                freeForL2Table = findFreeMemory(1, true, true);
            } else {
                freeForL2Table += 256;
            }
            unsigned int tableEntry = (unsigned int)freeForL2Table | 0x00000011;
            *(masterTableAddress + masterTableEntryNumber) = tableEntry;
            std::memset((void*)freeForL2Table, 0x0, 1024); // 256 entries * 4 bytes per entry = 1024 bytes
        } else {
            freeForL2Table = (address)((*(masterTableAddress + masterTableEntryNumber) >> 10) << 10);
        }
        
        for (int j = firstEntryNumber; (j < 256) && (j <= lastEntryNumber); ++j) {
            unsigned int tableEntry = firstL2Entry + ((i * 256) + j) * 4096;
            tableEntry |= 0x2;
            *(freeForL2Table + j) = tableEntry;
            firstEntryNumber = j;
        }
    }
}

void MMU::reservePages(MemoryType mem, int firstPageNumber, int nrOfPages) {
    for (int i = firstPageNumber; i < (firstPageNumber + nrOfPages); i++) {
        if (mem == INT_RAM) {
            m_occupiedPagesIntRam[i] = true;
        } else if (mem == EXT_DDR) {
            m_occupiedPagesExtDDR[i] = true;
        }
    }
}
address MMU::findFreeMemory(int nrOfPages, bool align, bool reserve) {
    address result = 0x0;
    int freePages = 0;
    for (int i = 0; (i < MAX_PAGES_IN_INT_RAM) && (result == 0x0); i++) {
        if ((!m_occupiedPagesIntRam[i]) && ((align) && ((freePages > 0) || ((i % nrOfPages) == 0)))) {
            freePages++;
            if (freePages == nrOfPages) {
                result = (address)(INT_RAM_START + (((i - nrOfPages) + 1) * 4096));
                if (reserve) {
                    reservePages(INT_RAM, (i - nrOfPages) + 1, nrOfPages);
                }
            }
        } else {
            freePages = 0;
        }
    }
    freePages = 0;
    for (int i = 0; (i < MAX_PAGES_IN_EXT_DDR) && (result == 0x0); i++) {
        if (!m_occupiedPagesExtDDR[i]) {
            freePages++;
            if (freePages == nrOfPages) {
                result = (address)(EXT_DDR_START + (((i - nrOfPages) + 1) * 4096));
                if (reserve) {
                    reservePages(EXT_DDR, (i - nrOfPages) + 1, nrOfPages);
                }
                
            }
        } else {
            freePages = 0;
        }
    }
    return result;
}

void MMU::initMemoryForTask(int taskId) {
    address savedTableAddress = m_taskMasterTableAddresses[taskId];
    if (savedTableAddress == (address)0x0) {
        if (taskId == 0) {
            unsigned int i;
            m_firstFreeInIntRam = &intRamStart;
            m_firstFreeInExtDDR = &extDDRStart;
            
            // reserve kernel memory
            unsigned int nrOfKernelPages = (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) / 0x1000);
            if (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) % 0x1000 > 0) {
                nrOfKernelPages++;
            }
            reservePages(INT_RAM, 0, nrOfKernelPages);
            reservePages(INT_RAM, 15, 1);

            nrOfKernelPages = (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) / 0x1000);
            if (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) % 0x1000 > 0) {
                nrOfKernelPages++;
            }
            reservePages(EXT_DDR, 0, nrOfKernelPages);
                        
            initDomainAccess();
            
            address tableAddress = &kernelMasterTable;
            setMasterTablePointerTo(tableAddress);
            // Initialize Master Table
            for (i = 0x00000000; i < 0xFFF00000; i += 0x00100000) {
                *tableAddress = i | 0xC12;
                tableAddress++;
            }
            *tableAddress = 0xFFF00C12;
            
            enableMMU();
            //lockFirstTLBEntry();
        } else {
            address masterTableAddress = findFreeMemory(4, true, true);
            address tableAddress = masterTableAddress;
            
            std::memset((void*)tableAddress, 0x0000, 4096 * 4);
            
            mapOneToOne(masterTableAddress, 0x14000, 0x1C);
            mapOneToOne(masterTableAddress, INT_RAM_START, (unsigned int)m_firstFreeInIntRam - INT_RAM_START);
            mapOneToOne(masterTableAddress, 0x4020FFC4, 0x3B);
            mapOneToOne(masterTableAddress, EXT_DDR_START, (unsigned int)m_firstFreeInExtDDR - EXT_DDR_START);
            
            setMasterTablePointerTo(masterTableAddress);
        }
    } else {
        setMasterTablePointerTo(savedTableAddress);
    }
    m_taskMasterTableAddresses[taskId] = taskMasterTableAddress;
    m_currentTask = taskId;
}
void MMU::loadPage(int pageNumber) {
    //TODO
}

void MMU::prepagePagesFor(int serviceId)  {
	//TODO: to be implemented
}

address MMU::parameterAddressFor(int serviceId)  {
	//TODO: to be implemented
	return (address)0x820F0000;
}

void MMU::handlePageFault() {
    asm("\t MRC p15, #0, r0, c6, c0, #2\n"); // Read instruction fault address register
    asm("\t LDR r1, globalVariable\n");
    asm("\t STR r0, [r1]\n");
}
