#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 10
#define MAX_PAGES_IN_MEMORY 8192 // 32MB mapped to 4KB pages

#include "API/dataTypes.h"

//TODO: create MMU-Object? (Kernel is also an object)

void mmu_initMemoryForTask(int taskId);
void mmu_loadPage(int pageNumber);

void mmu_prepagePagesFor(int serviceId);
address mmu_parameterAddressFor(int serviceId);

#endif /*MMU_H_*/
