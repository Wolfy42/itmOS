#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "Handler/IRQHandler.h"
#include "Handler/SWIHandler.h"
#include "Kernel/Task/TaskManager.h"
#include "Kernel/MMU/mmu.h"

// init all used Handlers
void initInterruptHandler(IRQHandler* irq, SWIHandler* swi, TaskManager* tm, MMU* mmu);

#endif /*INTERRUPTS_H_*/
