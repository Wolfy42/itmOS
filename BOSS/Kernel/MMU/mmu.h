#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 256
#define MAX_PAGES_IN_INT_RAM 16
#define MAX_PAGES_IN_EXT_DDR 65536
#define INT_RAM_START 0x40200000
#define EXT_DDR_START 0x82000000

#include "API/dataTypes.h"

enum MemoryType {
    INT_RAM, EXT_DDR
};

class MMU {
    private:
        static MMU INSTANCE;
        address m_taskMasterTableAddresses[MAX_MMU_TABLES];
        int m_currentTask;
        
        address m_firstFreeInIntRam;
        address m_firstFreeInExtDDR;
        
        bool m_occupiedPagesIntRam[MAX_PAGES_IN_INT_RAM];
        bool m_occupiedPagesExtDDR[MAX_PAGES_IN_EXT_DDR];
        
        void enableMMU();
        void initDomainAccess();
        void setMasterTablePointerTo(address tableAddress);
        
        void mapOneToOne(address masterTableAddress, unsigned int startAddress, unsigned int length);
        
        void clearTLB();
        void lockFirstTLBEntry();
        
        void reservePages(MemoryType mem, int firstPageNumber, int nrOfPages);
        address findFreeMemory(int nrOfPages, bool align, bool reserve);
        
        MMU();
    public:
        virtual ~MMU();
        
        static MMU* getInstance();
        void initMemoryForTask(int taskId);
        void loadPage(int pageNumber);

        void prepagePagesFor(int serviceId);
        address parameterAddressFor(int serviceId);

        void handlePageFault();        
};

#endif /*MMU_H_*/
