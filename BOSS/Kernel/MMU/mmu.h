#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 256
#define MAX_PAGES_IN_INT_RAM 16
#define MAX_PAGES_IN_EXT_DDR 65536

#define ROM_INTERRUPT_ENTRIES 0x14000
#define ROM_INTERRUPT_LENGTH 0x1C
#define INT_RAM_START 0x40200000
#define EXT_DDR_START 0x82000000

#define TASK_MEMORY_START 0x20000
#define TASK_MEMORY_END 0x1000000

#define MESSAGE_QUEUE_VIRTUAL_ADDRESS 0x20000000

#include "API/dataTypes.h"
#include "Kernel/Task/Task.h"

class Kernel;

enum MemoryType {
    INT_RAM, EXT_DDR
};

class MMU {
    private:
        Kernel* m_kernel;
        Task m_kernelTask;
        Task* m_tasks[MAX_MMU_TABLES];
        Task* m_currentTask;
        
        address m_firstFreeInIntRam;
        address m_firstFreeInExtDDR;
        
        void initKernelMMU();
        
        void enableMMU();
        void initDomainAccess();
        void setMasterTablePointerTo(address tableAddress);
        
        address createMasterTable();
        address createOrGetL2Table(address masterTableAddress, int masterTableEntryNumber);
        address createMappedPage(address masterTableAddress, address virtualAddress);
        void mapDirectly(address masterTableAddress, address virtualAddress, address physicalAddress);
        void mapOneToOne(address masterTableAddress, address startAddress, unsigned int length);
        
        void clearTLB();
        void lockFirstTLBEntry();
        
        bool isTaskPage(address pageAddress);
        int pageForAddress(MemoryType& type, unsigned int memAddress);
        address addressOfPage(MemoryType mem, int pageNumberInMemory);
        void reservePages(MemoryType mem, int firstPageNumber, int nrOfPages);
        void releasePages(MemoryType mem, int firstPageNumber, int nrOfPages);
        address findFreeMemory(int nrOfPages, bool align, bool reserve);
        
    public:
        MMU(Kernel* kernel);
        virtual ~MMU();
        
        void switchToKernelMMU();
        void initMemoryForTask(Task* task);
        void deleteTaskMemory(Task* task);
        
        void loadPage(int pageNumber);

        void prepagePagesFor(int serviceId);
        address parameterAddressFor(int serviceId);

        bool handlePrefetchAbort();  
        bool handleDataAbort();
};

#endif /*MMU_H_*/
