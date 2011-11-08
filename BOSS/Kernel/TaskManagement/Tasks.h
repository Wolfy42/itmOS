#ifndef TASKS_H_
#define TASKS_H_

#define MAX_TASKS 256

#include <stdlib.h>

typedef int TID_t;
enum Status { Ready, Running, Blocked };

// interrupt
#pragma SWI_ALIAS(48);
int swi();

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
	int stackPointer;
	// entry
	int initAddr;
	// already started
	bool hasBeenStarted;
} Task;

// logic variables
Task* _tasks[MAX_TASKS];
int nextTask = 0;
int activeTask = -1;


// create Task
TID_t createTask(char* name, int priority, int initAddress) {

	Task* t = (Task*) malloc(sizeof(Task));
	// init Task
	t->id = nextTask;
	t->name = name;
	t->priority = priority;
	t->initAddr = initAddress;
	t->hasBeenStarted = false;
	t->status = Ready;
	t->stackPointer = 0x8200A000 + (nextTask + 1) * 0x00010000;
	
	// add Task
	_tasks[nextTask] = t;

	// increase nextOne
	nextTask++;
	
	// return TaskID
	return t->id;	
}

// Scheduler - get next Task to Run
void scheduleNextTask() {

	while (_tasks[++activeTask % MAX_TASKS] == 0) {	
	}
	activeTask = activeTask % MAX_TASKS;
}

void initTasks() {

	int i = 0;
	for (i = 0; i < MAX_TASKS; i++) {
	
		_tasks[i] = NULL;	
	}	
}

#endif /*TASKS_H_*/
