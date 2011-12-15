#include <string.h>
#include "API/dataTypes.h"
#include "Kernel/Kernel.h"
#include "mmu.h"

asm("\t .bss _taskMasterTableAddress, 4\n" \
    "\t .bss _tempVariableForAsmAndCpp, 4\n" \
    "\t .global _taskMasterTableAddress\n" \
    "\t .global _tempVariableForAsmAndCpp\n" \
    "taskMasterTableAddress .field _taskMasterTableAddress, 32\n" \
    "tempVariableForAsmAndCpp .field _tempVariableForAsmAndCpp, 32\n");
extern address taskMasterTableAddress;
extern unsigned int tempVariableForAsmAndCpp;
extern volatile unsigned int kernelMasterTable;
extern volatile unsigned int intRamStart;
extern volatile unsigned int extDDRStart;
extern volatile unsigned int intvecsStart;


MMU::MMU(Kernel* kernel) {
    m_kernel = kernel;
    m_currentTask = NULL;
    m_firstFreeInIntRam = &intRamStart;
    m_firstFreeInExtDDR = &extDDRStart;
    

    for (int i = 0; i < MAX_TASKS; i++) {
        m_tasks[i] = NULL;
    }
    
    //Initialize MMU
    initKernelMMU();
}

void MMU::initKernelMMU() {
    // reserve kernel memory
    unsigned int nrOfKernelPages = (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) / 0x1000);
    if (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) % 0x1000 > 0) {
        nrOfKernelPages++;
    }
    m_kernel->getRAMManager()->reservePages(INT_RAM, 0, nrOfKernelPages);
    m_kernel->getRAMManager()->reservePages(INT_RAM, 15, 1);

    nrOfKernelPages = (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) / 0x1000);
    if (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) % 0x1000 > 0) {
        nrOfKernelPages++;
    }
    m_kernel->getRAMManager()->reservePages(EXT_DDR, 0, nrOfKernelPages);
                
    initDomainAccess();
    
    address tableAddress = &kernelMasterTable;
    m_kernelTask.masterTableAddress = tableAddress;
    
    setMasterTablePointerTo(tableAddress);
    // Initialize Master Table
    for (unsigned int i = 0x00000000; i < 0xFFF00000; i += 0x00100000) {
        *tableAddress = i | 0xC12;
        tableAddress++;
    }
    *tableAddress = 0xFFF00C12;

    enableMMU();
}

MMU::~MMU() {
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
    tempVariableForAsmAndCpp = EXT_DDR_START;
    asm("\t LDR  r1, tempVariableForAsmAndCpp\n");
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

address MMU::createMasterTable() {
    address masterTableAddress = m_kernel->getRAMManager()->findFreeMemory(4, true, true);
    std::memset((void*)masterTableAddress, 0x0000, 4096 * 4);
    return masterTableAddress;
}
address MMU::createOrGetL2Table(address masterTableAddress, int masterTableEntryNumber) {
    address result = 0x0;
    if (masterTableEntryNumber < 4096) {
        if (*(masterTableAddress + masterTableEntryNumber) == 0x0) {
            result = m_kernel->getRAMManager()->findFreeMemory(1, true, true);
            
            unsigned int tableEntry = (unsigned int)result | 0x00000011;
            *(masterTableAddress + masterTableEntryNumber) = tableEntry;
            
            std::memset((void*)result, 0x0, 1024); // 256 entries * 4 bytes per entry = 1024 bytes
        } else {
            result = (address)((*(masterTableAddress + masterTableEntryNumber) >> 10) << 10);
        }
    }
    return result;
}

address MMU::createMappedPage(address masterTableAddress, address virtualAddress) {
    address newPage = m_kernel->getRAMManager()->findFreeMemory(1, true, true);
    std::memset((void*)newPage, 0x0, 4096);
    
    mapDirectly(masterTableAddress, virtualAddress, newPage);
    return newPage;
}

void MMU::mapDirectly(address masterTableAddress, address virtualAddress, address physicalAddress) {
    unsigned int masterTableEntryNumber = (unsigned int)virtualAddress >> 20;
    address l2TableAddress = createOrGetL2Table(masterTableAddress, masterTableEntryNumber);
    
    address pageAddress = (address)(((unsigned int)physicalAddress >> 12) << 12);

    unsigned int l2TableEntryNumber = ((unsigned int)virtualAddress >> 12) - (((unsigned int)virtualAddress >> 12) & 0xFFF00);
    unsigned int tableEntry = (unsigned int)pageAddress | 0x2;
    *(l2TableAddress + l2TableEntryNumber) = tableEntry;
}

void MMU::mapOneToOne(address masterTableAddress, address startAddress, unsigned int length) {
    int nrOfMasterTableEntries = (length / 1048576) + 1;
    
    int firstEntryNumber = ((unsigned int)startAddress >> 12) - (((unsigned int)startAddress >> 12) & 0xFFF00);
    int lastEntryNumber = firstEntryNumber + (length / 4096);
    
    unsigned int firstL2Entry = ((unsigned int)startAddress >> 20) << 20;
    for (int i = 0; i < nrOfMasterTableEntries; i++) {
        
        unsigned int masterTableEntryNumber = (unsigned int)startAddress >> 20;
        address freeForL2Table = createOrGetL2Table(masterTableAddress, masterTableEntryNumber);
        
        if (freeForL2Table > 0x0) {
            for (int j = firstEntryNumber; (j < 256) && (j <= lastEntryNumber); ++j) {
                unsigned int tableEntry = firstL2Entry + ((i * 256) + j) * 4096;
                tableEntry |= 0x2;
                *(freeForL2Table + j) = tableEntry;
                firstEntryNumber = j;
            }
        } else {
            // TODO Handle full memory
        }
    }
}

bool MMU::isTaskPage(address pageAddress) {
    address intVecsPageStart = (address)((((unsigned int)&intvecsStart) >> 12) << 12);
    return !(((pageAddress >= (address)INT_RAM_START) && (pageAddress < m_firstFreeInIntRam))
        || ((pageAddress >= (address)EXT_DDR_START) && (pageAddress < m_firstFreeInExtDDR))
        || ((pageAddress >= (address)ROM_INTERRUPT_ENTRIES) && (pageAddress < (address)(ROM_INTERRUPT_ENTRIES + ROM_INTERRUPT_LENGTH)))
        || ((pageAddress >= intVecsPageStart) && (pageAddress < (address)(INT_RAM_START + INT_RAM_SIZE))));
}

void MMU::switchToKernelMMU() {
    setMasterTablePointerTo(m_kernelTask.masterTableAddress);
}

void MMU::initMemoryForTask(Task* task) {
    Task* savedTaskPointer = m_tasks[task->id];
    
    if (savedTaskPointer == NULL) {
        task->masterTableAddress = createMasterTable();
        
        mapOneToOne(task->masterTableAddress, (address)ROM_INTERRUPT_ENTRIES, ROM_INTERRUPT_LENGTH);
        mapOneToOne(task->masterTableAddress, (address)INT_RAM_START, (unsigned int)m_firstFreeInIntRam - INT_RAM_START);
        mapOneToOne(task->masterTableAddress, &intvecsStart, 0x3B);
        mapOneToOne(task->masterTableAddress, (address)EXT_DDR_START, (unsigned int)m_firstFreeInExtDDR - EXT_DDR_START);
        
        task->messageQueueAddress = createMappedPage(task->masterTableAddress, (address)MESSAGE_QUEUE_VIRTUAL_ADDRESS);
        
        // Fake loader
        unsigned int startAddress = task->tcb.restartAddress;
        address newPage = createMappedPage(task->masterTableAddress, (address)startAddress);
        
        address codeLocation = task->codeLocation + ((startAddress - TASK_MEMORY_START) / 4);
        // load needed instructions into new page
        std::memcpy((void*)newPage, (void*)(codeLocation), 4096);
        
        setMasterTablePointerTo(task->masterTableAddress);
        
        m_tasks[task->id] = task;
    } else {
        setMasterTablePointerTo(savedTaskPointer->masterTableAddress);
    }
    m_currentTask = task;
}

void MMU::deleteTaskMemory(Task* task) {
    address masterTableAddress = task->masterTableAddress;
    if (masterTableAddress != 0x0) {
        MemoryType type;
        
        for (unsigned int masterTableEntry = 0; masterTableEntry < 4096; masterTableEntry++) {
            address l2TableAddress = (address)(((*(masterTableAddress + masterTableEntry)) >> 10) << 10);
            if (l2TableAddress != 0x0) {
                for (unsigned int l2TableEntry = 0; l2TableEntry < 256; l2TableEntry++) {
                    address pageAddress = (address)(((*(l2TableAddress + l2TableEntry)) >> 12) << 12);
                    if ((pageAddress != 0x0) && (isTaskPage(pageAddress))) {
                        
                        int pageNumber = m_kernel->getRAMManager()->pageForAddress(type, (unsigned int)pageAddress);
                        m_kernel->getRAMManager()->releasePages(type, pageNumber, 1);
                    }
                    *(l2TableAddress + l2TableEntry) = 0x0;
                }
                int pageNumber = m_kernel->getRAMManager()->pageForAddress(type, (unsigned int)l2TableAddress);
                m_kernel->getRAMManager()->releasePages(type, pageNumber, 1);
                *(masterTableAddress + masterTableEntry) = 0x0;
            }
        }
        int pageNumber = m_kernel->getRAMManager()->pageForAddress(type, (unsigned int)masterTableAddress);
        m_kernel->getRAMManager()->releasePages(type, pageNumber, 4);
    }
    m_tasks[task->id] = NULL;
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

bool MMU::handlePrefetchAbort() {
    Task* currentTask = m_currentTask;
    switchToKernelMMU();
    m_kernel->getTaskManager()->kill(currentTask->id);
    return true;
}

bool MMU::handleDataAbort() {
    asm("\t MRC p15, #0, r0, c6, c0, #0\n"); // Read data foult address register
    asm("\t LDR r1, tempVariableForAsmAndCpp\n");
    asm("\t STR r0, [r1]\n");
    // TODO check for read / write permissions
    
    bool doContextSwitch = false;
    unsigned int accessedAddress = tempVariableForAsmAndCpp;
    
    if ((accessedAddress % 0x4 == 0x0) && (accessedAddress >= TASK_MEMORY_START) && (accessedAddress < TASK_MEMORY_END)) {
        Task* currentTask = m_currentTask;
        switchToKernelMMU();
        createMappedPage(currentTask->masterTableAddress, (address)accessedAddress);
        initMemoryForTask(currentTask);
        doContextSwitch = false;
    } else {
        Task* currentTask = m_currentTask;
        switchToKernelMMU();
        m_kernel->getTaskManager()->kill(currentTask->id);
        doContextSwitch = true;
    }
    return doContextSwitch;
}
