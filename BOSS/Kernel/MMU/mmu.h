#ifndef MMU_H_
#define MMU_H_

#define MAX_MMU_TABLES 10
#define MAX_PAGES_IN_MEMORY ((32 * 1024) / 4); // 32MB mapped to 4KB pages
void mmu_initMemoryForTask(int taskId);
void mmu_loadPage(int pageNumber);

#endif /*MMU_H_*/
