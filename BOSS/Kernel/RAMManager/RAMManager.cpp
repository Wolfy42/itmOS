#include <string.h>
#include "Lib/bitOperations.h"
#include "RAMManager.h"

bool occupiedPagesIntRam[MAX_PAGES_IN_INT_RAM / 8];
bool occupiedPagesExtDDR[MAX_PAGES_IN_EXT_DDR / 8];


RAMManager::RAMManager() {
    // Initialize fields
    int entrySize = sizeof(bool) * 8; // Size in bit
    int max = 0;
    if (MAX_PAGES_IN_EXT_DDR > MAX_PAGES_IN_INT_RAM) {
        max = MAX_PAGES_IN_EXT_DDR / entrySize;
    } else {
        max = MAX_PAGES_IN_INT_RAM / entrySize;
    }
    
    for (int i = 0; i < max; i++) {
        if (i < (MAX_PAGES_IN_EXT_DDR / entrySize)) {
            occupiedPagesExtDDR[i] = 0x0;
        }
        if (i < (MAX_PAGES_IN_INT_RAM / entrySize)) {
            occupiedPagesIntRam[i] = 0x0;
        }
    }
}

RAMManager::~RAMManager() {
}

void RAMManager::reservePage(MemoryType mem, int pageNumber) {
    int entryNumber = (pageNumber / (sizeof(address) * 8));
    int bitNumber = (pageNumber % (sizeof(address) * 8));

    if ((mem == INT_RAM) && (pageNumber < MAX_PAGES_IN_INT_RAM)) {
        setBit(((address)occupiedPagesIntRam) + entryNumber, bitNumber);
    } else if ((mem == EXT_DDR) && (pageNumber < MAX_PAGES_IN_EXT_DDR)) {
        setBit(((address)occupiedPagesExtDDR) + entryNumber, bitNumber);
    }
}

bool RAMManager::isOccupied(MemoryType mem, int pageNumber) {
    int entryNumber = (pageNumber / (sizeof(address) * 8));
    int bitNumber = (pageNumber % (sizeof(address) * 8));
    
    bool result = false;
    if ((mem == INT_RAM) && (pageNumber < MAX_PAGES_IN_INT_RAM)) {
        result = readBit(((address)occupiedPagesIntRam) + entryNumber, bitNumber);
    } else if ((mem == EXT_DDR) && (pageNumber < MAX_PAGES_IN_EXT_DDR)) {
        result = readBit(((address)occupiedPagesExtDDR) + entryNumber, bitNumber);
    }
    
    return result;
}

void RAMManager::releasePage(MemoryType mem, int pageNumber) {
    int entryNumber = (pageNumber / (sizeof(address) * 8));
    int bitNumber = (pageNumber % (sizeof(address) * 8));

    if ((mem == INT_RAM) && (entryNumber < MAX_PAGES_IN_INT_RAM)) {
        unsetBit((address)(((address)occupiedPagesIntRam) + entryNumber), bitNumber);
    } else if ((mem == EXT_DDR) && (entryNumber < MAX_PAGES_IN_EXT_DDR)) {
        unsetBit((address)(((address)occupiedPagesExtDDR) + entryNumber), bitNumber);
    }
}

int RAMManager::pageForAddress(MemoryType& type, unsigned int memAddress) {
    int result = -1;
    if ((memAddress >= INT_RAM_START) && (memAddress < INT_RAM_START + INT_RAM_SIZE)) {
        result = (memAddress - INT_RAM_START) / 4096;
        type = INT_RAM;
    } else if ((memAddress >= EXT_DDR_START) && (memAddress < EXT_DDR_START + EXT_DDR_SIZE)) {
        result = (memAddress - EXT_DDR_START) / 4096;
        type = EXT_DDR;
    }
    return result;
}

address RAMManager::addressOfPage(MemoryType mem, int pageNumberInMemory) {
    address result = 0x0;
    switch (mem) {
        case INT_RAM:
            result = (address)(INT_RAM_START + (pageNumberInMemory * 4096));
            break;
        case EXT_DDR:
            result = (address)(EXT_DDR_START + (pageNumberInMemory * 4096));
            break;
    }
    return result;
}
void RAMManager::reservePages(MemoryType mem, int firstPageNumber, int nrOfPages) {
    for (int i = firstPageNumber; i < (firstPageNumber + nrOfPages); i++) {
        reservePage(mem, i);
    }
}
void RAMManager::releasePages(MemoryType mem, int firstPageNumber, int nrOfPages) {
    for (int i = firstPageNumber; i < (firstPageNumber + nrOfPages); ++i) {
        releasePage(mem, i);
        std::memset((void*)addressOfPage(mem, i), 0x0, 4096);
    }
}

address RAMManager::findFreeMemory(MemoryType mem, int nrOfPages, bool align, bool reserve) {
    address result = 0x0;
    int freePages = 0;
    for (int i = 0; (i < maxPagesIn(mem)) && (result == 0x0); i++) {
        if ((!isOccupied(mem, i)) && ((!align) || ((freePages > 0) || ((i % nrOfPages) == 0)))) {
            freePages++;
            if (freePages == nrOfPages) {
                result = addressOfPage(mem, (i - nrOfPages) + 1);
                if (reserve) {
                    reservePages(mem, (i - nrOfPages) + 1, nrOfPages);
                }
            }
        } else {
            freePages = 0;
        }
    }
    return result;
}

address RAMManager::findFreeMemory(int nrOfPages, bool align, bool reserve) {
    address result = findFreeMemory(INT_RAM, nrOfPages, align, reserve);
    if (result == 0x0) {
        result = findFreeMemory(EXT_DDR, nrOfPages, align, reserve);
    }
    return result;
}

int RAMManager::maxPagesIn(MemoryType mem) {
    int result = 0;
    switch (mem) {
        case INT_RAM:
            result = MAX_PAGES_IN_INT_RAM;
            break;
        case EXT_DDR:
            result = MAX_PAGES_IN_EXT_DDR;
            break;
    }
    return result;
}
