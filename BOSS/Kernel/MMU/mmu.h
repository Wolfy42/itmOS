#ifndef MMU_H_
#define MMU_H_

#define TASK_MEMORY_START 0x20000
#define TASK_MEMORY_END 0x1000000

#define MESSAGE_QUEUE_VIRTUAL_ADDRESS 0x20000000
#define MESSAGE_QUEUE_SIZE            0x00001000

#define TASK_STACK_START 0x10000000
#define TASK_STACK_SIZE  0x00002000

#define TASK_SYSMEM_START 0x10002000
#define TASK_SYSMEM_SIZE  0x00002000

#include "API/dataTypes.h"
#include "Kernel/Task/Task.h"
#include "Kernel/Task/TaskManager.h"

class Kernel;

class MMU {
    private:
        Kernel* m_kernel;
        Task m_kernelTask;
        Task* m_tasks[MAX_TASKS];
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
        void mapOneToOne(address masterTableAddress, address startAddress, unsigned int length, bool userAccess, bool kernelAccess);
        
        void clearTLB();
        
        bool isTaskPage(address pageAddress);
        
        bool isLegal(unsigned int accessedAddress, unsigned int faultStatus);
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
