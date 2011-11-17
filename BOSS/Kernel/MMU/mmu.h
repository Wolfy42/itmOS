#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 10
void mmu_initMemoryForTask(int taskId);
void mmu_loadPage(int pageNumber);

#endif /*MMU_H_*/
