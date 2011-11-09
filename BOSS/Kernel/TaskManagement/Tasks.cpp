#include "Tasks.h"








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
	while (_tasks[++nextTask % MAX_TASKS] != NULL) {	
	}
	nextTask = nextTask % MAX_TASKS;
	
	// return TaskID
	return t->id;	
}

// delete Task
void deleteTask(int TID_t) {

	free(_tasks[TID_t]);	
}

// Scheduler - get next Task to Run
void scheduleNextTask() {

	while (_tasks[++activeTask % MAX_TASKS] == NULL) {	
	}
	activeTask = activeTask % MAX_TASKS;
}

// init Task Array with NULL
void initTasks() {

	int i = 0;
	for (i = 0; i < MAX_TASKS; i++) {
	
		_tasks[i] = NULL;	
	}	
}


void exitTask() {
	
	//printf("task done");
}
