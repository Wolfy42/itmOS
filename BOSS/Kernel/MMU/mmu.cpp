#include <string.h>
#include <list>
#include "Lib/bitOperations.h"
#include "API/dataTypes.h"
#include "Kernel/Kernel.h"
#include "mmu.h"
#include "FaultStatusFlags.h"

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
    
    //Initialize MMU
    initKernelMMU();
}

void MMU::initKernelMMU() {
    // reserve kernel memory
    unsigned int nrOfKernelPages = (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) / 0x1000);
    if (((unsigned int)m_firstFreeInIntRam - INT_RAM_START) % 0x1000 > 0) {
        nrOfKernelPages++;
    }
    // Pages needed by kernel in intRAM
    m_kernel->getRAMManager()->reservePages(INT_RAM, 0, nrOfKernelPages);
    // Top page in intRAM for intvecs
    m_kernel->getRAMManager()->reservePages(INT_RAM, 15, 1);

    nrOfKernelPages = (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) / 0x1000);
    if (((unsigned int)m_firstFreeInExtDDR - EXT_DDR_START) % 0x1000 > 0) {
        nrOfKernelPages++;
    }
    
    // Pages needed by kernel in extDDR
    m_kernel->getRAMManager()->reservePages(EXT_DDR, 0, nrOfKernelPages);
    // Top 768 pages in extDDR for frame buffer
    m_kernel->getRAMManager()->reservePages(EXT_DDR, 0x01FFFD00, 768);

    initDomainAccess();
    
    address tableAddress = &kernelMasterTable;
    m_kernelTask.masterTableAddress = tableAddress;
    
    setMasterTablePointerTo(tableAddress);
    // Initialize Master Table
    for (unsigned int i = 0x00000000; i < 0xFFF00000; i += 0x00100000) {
        *tableAddress = i | 0x000000C12;
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
address MMU::createOrGetL2Table(address masterTableAddress, int masterTableEntryNumber, unsigned char domainNumber) {
    address result = 0x0;
    if (masterTableEntryNumber < 4096) {
        if (*(masterTableAddress + masterTableEntryNumber) == 0x0) {
            result = m_kernel->getRAMManager()->findFreeMemory(1, true, true);
            
            // 0b10001 means coarse page table
            unsigned int tableEntry = (unsigned int)result | 0x00000011;
            // Set the domain
            tableEntry |= (domainNumber << 5);
            
            *(masterTableAddress + masterTableEntryNumber) = tableEntry;
            
            std::memset((void*)result, 0x0, 1024); // 256 entries * 4 bytes per entry = 1024 bytes
        } else {
            result = (address)((*(masterTableAddress + masterTableEntryNumber) >> 10) << 10);
        }
    }
    return result;
}

unsigned char MMU::getAccessFlagForDomain(unsigned char domainNumber) {
    unsigned char result = 0;
    switch (domainNumber) {
        case 0:
            result = 3;
            break;
        default:
            result = 1;
            break;
    }
    return result;
}
address MMU::createMappedPage(address masterTableAddress, address virtualAddress, unsigned char domainNumber) {
    address newPage = m_kernel->getRAMManager()->findFreeMemory(1, true, true);
    std::memset((void*)newPage, 0x0, 4096);
    
    mapDirectly(masterTableAddress, virtualAddress, newPage, domainNumber);
    return newPage;
}

void MMU::mapDirectly(address masterTableAddress, address virtualAddress, address physicalAddress, unsigned char domainNumber) {
    unsigned int masterTableEntryNumber = (unsigned int)virtualAddress >> 20;
    address l2TableAddress = createOrGetL2Table(masterTableAddress, masterTableEntryNumber, domainNumber);
    if (l2TableAddress != 0x0) {
        address pageAddress = (address)(((unsigned int)physicalAddress >> 12) << 12);
    
        unsigned int l2TableEntryNumber = ((unsigned int)virtualAddress >> 12) - (((unsigned int)virtualAddress >> 12) & 0xFFF00);
        
        // 0x2 means small page (0b10)
        unsigned int tableEntry = (unsigned int)pageAddress | 0x00000002;
        
        unsigned char accessFlag = getAccessFlagForDomain(domainNumber);
        // Set the AP bits
        tableEntry |= (accessFlag << 4);
        tableEntry |= (accessFlag << 6);
        tableEntry |= (accessFlag << 8);
        tableEntry |= (accessFlag << 10);
        
        *(l2TableAddress + l2TableEntryNumber) = tableEntry;
    } else {
        // TODO Handle full memory
    }
}

void MMU::mapOneToOne(address masterTableAddress, address startAddress, unsigned int length, unsigned char domainNumber) {
    // Each entry maps 4096 bytes = 0x1000
    for (int i = 0; i < length; i += 0x1000) {
        // Map the next page. because startAddress is of type address, it adds 4 * i automatically => take i / 4
        mapDirectly(masterTableAddress, startAddress + (i / 4), startAddress + (i / 4), domainNumber);
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
    
    if (task->masterTableAddress == NULL) {
        task->masterTableAddress = createMasterTable();
        
        mapOneToOne(task->masterTableAddress, (address)ROM_INTERRUPT_ENTRIES, ROM_INTERRUPT_LENGTH, 0);
        mapOneToOne(task->masterTableAddress, (address)INT_RAM_START, (unsigned int)m_firstFreeInIntRam - INT_RAM_START, 0);
        mapOneToOne(task->masterTableAddress, &intvecsStart, 0x3B, 0);
        mapOneToOne(task->masterTableAddress, (address)EXT_DDR_START, (unsigned int)m_firstFreeInExtDDR - EXT_DDR_START, 0);
        
        task->memoryManager = (MemoryManager*)createMappedPage(task->masterTableAddress, (address)MESSAGE_QUEUE_VIRTUAL_ADDRESS, 0);
        int virtualOffset = (int)MESSAGE_QUEUE_VIRTUAL_ADDRESS - (int)task->memoryManager;
        MemoryManager::getInstanceAt((address)task->memoryManager, virtualOffset);
        
        mapHardwareRegisters(task);
        
        // Map the code of the task directly
        for (int i = 0; i < task->pageCount; i++)  {
            // The next virtual address is the first address plus 4096 bytes (4KB)
            address virtualAddress = (address)(task->tcb.restartAddress + (i * 4096));
            // The next physical address is the first address plus 4096 bytes (4KB)
            address physicalAddress = (address)(((unsigned int)(task->codeLocation)) + (i * 4096));
            mapDirectly(task->masterTableAddress, virtualAddress, physicalAddress, 0);
        }
        
        setMasterTablePointerTo(task->masterTableAddress);
        
    } else {
        setMasterTablePointerTo(task->masterTableAddress);
    }
    m_currentTask = task;
}

void MMU::mapHardwareRegisters(Task* task) {    
    std::list<address>* taskRegisters = task->taskRegisters;
    if (taskRegisters != 0x0) {
        std::list<address>::const_iterator iter;
        
        for (iter = taskRegisters->begin(); iter != taskRegisters->end(); iter++) {
            mapOneToOne(task->masterTableAddress, *iter, 1, 0);
        }
    }
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
    task->masterTableAddress = NULL;
}

void MMU::loadPage(int pageNumber) {
    //TODO
}

bool MMU::isLegal(unsigned int accessedAddress, unsigned int faultStatus) {
    bool writeAccess = readBit(&faultStatus, 11);
    unsigned int statusField = (faultStatus & 0xF);
    bool sdBit = readBit(&faultStatus, 12);
    bool sBit = readBit(&faultStatus, 10);
    statusField |= (sdBit << 6);
    statusField |= (sBit << 5);
    
    bool result = false;
    
    if (writeAccess) {
        switch (statusField) {
            case PERMISSION_FAULT_SECTION:
            case PERMISSION_FAULT_PAGE:
                result = false;
                break;
            case TRANSLATION_FAULT_SECTION:
            case TRANSLATION_FAULT_PAGE:
                result = (((accessedAddress >= TASK_STACK_START) && (accessedAddress < TASK_STACK_START + TASK_STACK_SIZE))
                       || ((accessedAddress >= TASK_SYSMEM_START) && (accessedAddress < TASK_SYSMEM_START + TASK_SYSMEM_SIZE))
                       || ((accessedAddress >= MESSAGE_QUEUE_VIRTUAL_ADDRESS) && (accessedAddress < MESSAGE_QUEUE_VIRTUAL_ADDRESS + MESSAGE_QUEUE_SIZE))
                       || ((accessedAddress >= TASK_ADDITIONAL_MEMORY_START) && (accessedAddress < TASK_ADDITIONAL_MEMORY_START + TASK_ADDITIONAL_MEMORY_SIZE)));
                break;
            case DEBUG_EVENT:
                result = true;
                break;
            default:
                result = false;
                break;        
        }
    } else {
       result = false;
    }
    
    return result;
}

RAMManager* MMU::getRAMManager() {
    return m_kernel->getRAMManager();
}

bool MMU::handlePrefetchAbort() {
    asm("\t MRC p15, #0, r0, c6, c0, #2\n");
    asm("\t MRC p15, #0, r1, c5, c0, #1\n");
    Task* currentTask = m_currentTask;
    switchToKernelMMU();
    m_kernel->getTaskManager()->kill(currentTask->id);
    return true;
}

bool MMU::handleDataAbort() {
    bool doContextSwitch = false;
    // Get the accessed address
    asm("\t MRC p15, #0, r0, c6, c0, #0\n"); // Read data fault address register
    asm("\t LDR r1, tempVariableForAsmAndCpp\n");
    asm("\t STR r0, [r1]\n");
    unsigned int accessedAddress = tempVariableForAsmAndCpp;
    
    // Get the abort status
    asm("\t MRC p15, #0, r0, c5, c0, #0\n");
    asm("\t LDR r1, tempVariableForAsmAndCpp\n");
    asm("\t STR r0, [r1]\n");
    unsigned int faultStatus = tempVariableForAsmAndCpp;
    
    if (isLegal(accessedAddress, faultStatus)) {
        Task* currentTask = m_currentTask;
        switchToKernelMMU();
        createMappedPage(currentTask->masterTableAddress, (address)accessedAddress, 0);
        initMemoryForTask(currentTask);
        doContextSwitch = false;
    } else {
        if (m_currentTask != NULL) {
            Task* currentTask = m_currentTask;
            switchToKernelMMU();
            m_kernel->getTaskManager()->kill(currentTask->id);
            doContextSwitch = true;
        }
    }
    return doContextSwitch;
}
