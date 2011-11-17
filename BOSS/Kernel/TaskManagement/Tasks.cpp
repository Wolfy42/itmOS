#include "Tasks.h"

Task* _tasks[MAX_TASKS];
int activeTask = -1;

// create Task
TID_t createTask(char* name, int priority, int initAddress) {

	int nextTask = getNextTaskId();

	if (nextTask != -1) {

		// init task
		Task* t = (Task*) malloc(sizeof(Task));
		t->id = nextTask;
		t->name = name;
		t->priority = priority;
		t->initAddr = initAddress;
		t->hasBeenStarted = false;
		t->status = Ready;
		t->stackPointer = 0x8200A000 + (nextTask + 1) * 0x00010000;
	
		// add Task
		_tasks[nextTask] = t;

		// return TaskID
		return t->id;
	} else {
		return -1;
	}
}

// delete Task
void deleteTask(TID_t taskId) {

	free(_tasks[taskId]);
	_tasks[taskId] = NULL;
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
	
	performSyscall(EXIT, &activeTask);
}

int getNextTaskId() {

	// iterate through all tasks to get the next free slot
	// start everytime at the beginning
	for (int i = 0; i < MAX_TASKS; i++) {

		if (_tasks[i] == NULL) {

			return i;
		}
	}

	// no free slots available - if this line is ever executed call me on my cell phone!
	return -1;
}
