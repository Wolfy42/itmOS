#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "Handler/IRQHandler.h"
#include "Handler/SWIHandler.h"
#include "Kernel/Task/TaskManager.h"

// Forward-declaration
class SWIHandler;

// init all used Handlers
void initInterruptHandler(IRQHandler* irq, SWIHandler* swi, TaskManager* tm);

#endif /*INTERRUPTS_H_*/
