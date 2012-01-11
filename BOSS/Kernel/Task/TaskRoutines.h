#ifndef TASKROUTINES_H_
#define TASKROUTINES_H_

#include "TaskManager.h"
#include "API/systemCalls.h"

// remember it just can use ONE TaskManager
void initTaskRoutines(TaskManager* tm);

// exit Point for a Standard - Task
// this performs a system Calls (EXIT)
void exitTask();

#endif /*TASKROUTINES_H_*/
