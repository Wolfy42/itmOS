#include "API/dataTypes.h"
#include "mmu.h"

asm("\t .bss _taskMasterTableAddress, 4\n" \
    "\t .global _taskMasterTableAddress\n" \
    "taskMasterTableAddress .field _taskMasterTableAddress, 32");
extern address taskMasterTableAddress;
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
            occupiedPagesExtDDR[i] = false;
        }
        if (i < MAX_PAGES_IN_INT_RAM) {
            occupiedPagesIntRam[i] = false;
        }
        if (i < MAX_MMU_TABLES) {
            taskMasterTableAddresses[i] = 0x0;
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
    asm("\t MOV r0, #0x5557\n");
    asm("\t MOVT r0, #0x5555\n");
    asm("\t MCR p15, #0, r0, c3, c0, #0\n");
}

void MMU::clearTLB() {
    asm("\t MOV r0, #0x0\n");
    asm("\t MCR p15, #0, r0, c8, c7, #0\n");
}

void MMU::setMasterTablePointerTo(address tableAddress) {
    taskMasterTableAddress = tableAddress;
    unsigned int tempAddress = (unsigned int)taskMasterTableAddress & 0xFFFFC000;
    taskMasterTableAddress = (address)tempAddress;
    
    asm("\t LDR r1, taskMasterTableAddress\n");
    asm("\t LDR r1, [r1]\n");
    asm("\t MCR p15, #0, r1, c2, c0, #0\n");
    
    clearTLB();
    asm("\t MRC p15, #0, r2, c2, c0, #0\n");
    asm("\t MRC p15, #0, r3, c1, c0, #0\n");
}

address MMU::findFreeMemory(int nrOfPages, bool align) {
    address result = 0x0;
    int freePages = 0;
    for (int i = 0; (i < MAX_PAGES_IN_INT_RAM) && (result == 0x0); i++) {
        if ((!occupiedPagesIntRam[i]) && ((align) && ((freePages > 0) || ((i % nrOfPages) == 0)))) {
            freePages++;
            if (freePages == nrOfPages) {
                result = (address)(INT_RAM_START + (((i - nrOfPages) + 1) * 4096));
            }
        } else {
            freePages = 0;
        }
    }
    freePages = 0;
    for (int i = 0; (i < MAX_PAGES_IN_EXT_DDR) && (result == 0x0); i++) {
        if (!occupiedPagesExtDDR[i]) {
            freePages++;
            if (freePages == nrOfPages) {
                result = (address)(EXT_DDR_START + (((i - nrOfPages) + 1) * 4096));
            }
        } else {
            freePages = 0;
        }
    }
    return result;
}

void MMU::initMemoryForTask(int taskId) {
    address savedTableAddress = taskMasterTableAddresses[taskId];
    if (savedTableAddress == (address)0x0) {
        if (taskId == 0) {
            unsigned int i;
            firstFreeInIntRam = &intRamStart;
            firstFreeInExtDDR = &extDDRStart;
            
            unsigned int nrOfKernelPages = (((unsigned int)firstFreeInIntRam - INT_RAM_START) / 0x1000);
            if (((unsigned int)firstFreeInIntRam - INT_RAM_START) % 0x1000 > 0) {
                nrOfKernelPages++;
            }
            // reserve kernel memory
            for (i = 0x0; i < nrOfKernelPages; i++) {
                occupiedPagesIntRam[i] = true;
            }
            nrOfKernelPages = (((unsigned int)firstFreeInExtDDR - EXT_DDR_START) / 0x1000);
            if (((unsigned int)firstFreeInExtDDR - EXT_DDR_START) % 0x1000 > 0) {
                nrOfKernelPages++;
            }
            for (i = 0x0; i < nrOfKernelPages; i++) {
                occupiedPagesExtDDR[i] = true;
            }
                        
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
        } else {
            address masterTableAddress = findFreeMemory(4, true);
            address tableAddress = masterTableAddress;
            
            for (int i = 0; i < 4096; i++) {
                *tableAddress = 0x0;
                tableAddress++;
            }
            
            taskMasterTableAddresses[taskId] = masterTableAddress;
            setMasterTablePointerTo(masterTableAddress);
        }
    } else {
        if (taskId > 0) {
            setMasterTablePointerTo(savedTableAddress);
        }
    }
    taskMasterTableAddresses[taskId] = taskMasterTableAddress;
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
