#ifndef TASKS_H_
#define TASKS_H_

#define MAX_TASKS 256

#include "HAL/Timer/HalTimerDriver.h"
#include "BOSSAPI/systemCalls.h"
#include "Lib/Rand.h"
#include "Lib/Time.h"
#include <stdlib.h>
#include <stdio.h>

typedef int TID_t;
enum Status { Ready, Running, Blocked };

struct TCB {
	int CPSR;
	int restartAddress;
	int R0;
	int R1;
	int R2;
	int R3;
	int R4;
	int R5;
	int R6;
	int R7;
	int R8;
	int R9;
	int R10;
	int R11;
	int R12;
	int R13;
	int R14;
};

typedef struct {
	
	// id of task
	TID_t id;
	// name of task
	char* name;
	// status of task
	Status status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
	// registers
	TCB tcb;

} Task;

// logic variables
extern Task* _tasks[MAX_TASKS];
extern int activeTask;


// create Task
TID_t createTask(char* name, int priority, int initAddress);

// delete Task
void deleteTask(TID_t taskId);

// Scheduler - get next Task to Run
void scheduleNextTask();

// init Task Array with NULL
void initTasks();

// returns the next free task id
int getNextTaskId();

void exitTask();

#endif /*TASKS_H_*/
