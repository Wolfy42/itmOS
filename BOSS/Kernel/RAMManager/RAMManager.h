#ifndef RAMMANAGER_H_
#define RAMMANAGER_H_

#define MAX_PAGES_IN_INT_RAM 16
#define MAX_PAGES_IN_EXT_DDR 8192

#define INT_RAM_START 0x40200000
#define INT_RAM_SIZE  0x00010000

#define EXT_DDR_START 0x82000000
#define EXT_DDR_SIZE  0x02000000

#define ROM_INTERRUPT_ENTRIES 0x14000
#define ROM_INTERRUPT_LENGTH 0x1C

#include <string.h>

#include "API/dataTypes.h"
#include "Lib/bitOperations.h"

enum MemoryType {
    INT_RAM, EXT_DDR
};

class RAMManager {
    private:
        void reservePage(MemoryType mem, int pageNumber);
        void releasePage(MemoryType mem, int pageNumber);
        bool isOccupied(MemoryType mem, int pageNumber);
        
        address findFreeMemory(MemoryType mem, int nrOfPages, bool align, bool reserve);
    public:
    	RAMManager();
    	virtual ~RAMManager();
        
        address findFreeMemory(int nrOfPages, bool align, bool reserve);
        int pageForAddress(MemoryType& type, unsigned int memAddress);
        address addressOfPage(MemoryType mem, int pageNumberInMemory);
        
        void reservePages(MemoryType mem, int firstPageNumber, int nrOfPages);
        void releasePages(MemoryType mem, int firstPageNumber, int nrOfPages);
        
        int maxPagesIn(MemoryType mem);
};

#endif /*RAMMANAGER_H_*/
