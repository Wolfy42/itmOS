#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 256
#define MAX_PAGES_IN_INT_RAM 16
#define MAX_PAGES_IN_EXT_DDR 65536
#define INT_RAM_START 0x40200000
#define EXT_DDR_START 0x82000000

#include "API/dataTypes.h"

class MMU {
    private:
        static MMU INSTANCE;
        address taskMasterTableAddresses[MAX_MMU_TABLES];
        address firstFreeInIntRam;
        address firstFreeInExtDDR;
        bool occupiedPagesIntRam[MAX_PAGES_IN_INT_RAM];
        bool occupiedPagesExtDDR[MAX_PAGES_IN_EXT_DDR];
        
        void enableMMU();
        void initDomainAccess();
        void clearTLB();
        void setMasterTablePointerTo(address tableAddress);
        address findFreeMemory(int nrOfPages, bool align);
        
        MMU();
    public:
        virtual ~MMU();
        
        static MMU* getInstance();
        void initMemoryForTask(int taskId);
        void loadPage(int pageNumber);
        
        void prepagePagesFor(int serviceId);
        address parameterAddressFor(int serviceId);
        
};

#endif /*MMU_H_*/
