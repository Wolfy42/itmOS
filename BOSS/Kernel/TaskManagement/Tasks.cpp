#include "Tasks.h"

Task* _tasks[MAX_TASKS];
int activeTask = 0;

// create Task
TID_t createTask(char* name, int priority, int initAddress) {

	int nextTask = getNextTaskId();

	if (nextTask != -1) {

		// init task
		Task* t = (Task*) malloc(sizeof(Task));
		t->id = nextTask;
		t->name = name;

		// to ensure a valid priority
		if (priority < 0) {
			t->priority = 0;
		} else if (priority > 100) {
			t->priority = 100;
		} else {
			t->priority = priority;
		}

		t->tcb.restartAddress = initAddress;
		t->tcb.R13 = 0x8200E000 + (nextTask + 1) * 0x00010000;
		t->tcb.CPSR = 0;
		t->tcb.R0 = 0;
		t->tcb.R1 = 0;
		t->tcb.R2 = 0;
		t->tcb.R3 = 0;
		t->tcb.R4 = 0;
		t->tcb.R5 = 0;
		t->tcb.R6 = 0;
		t->tcb.R7 = 0;
		t->tcb.R8 = 0;
		t->tcb.R9 = 0;
		t->tcb.R10 = 0;
		t->tcb.R11 = 0;
		t->tcb.R12 = 0;
		t->tcb.R13 = 0;
		t->tcb.R14 = 0;

		t->status = Ready;
		//t->stackPointer = 0x8200A000 + (nextTask + 1) * 0x00010000;
	
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

/* ---------------------------------------------------------
 * SteMar-Scheduler v0.2gamma (Stefan & Martin)
 *
 * The Scheduler schedules tasks by using its
 * priorities and a smart/funny/magic randomizer.
 * Also the performance is funny - but what shells?
 *
 * Don't try to understand the code - i don't understand it either!
 * ITS MAGIC!
 *
 * This scheduler is licensed under the SMNPL
 * (StefanMartinNotPublicLicense)
 *
 * CAUTION: THIS SCHEDULER MAY HARM YOUR BOARD!
 *
 * If your board is destroyed don't call us - WE CALL YOU!
 * ---------------------------------------------------------
 */
void scheduleNextTask() {

	
	int prioritySum = 0;
	int taskSum = 0;
	float level = 0.0;
	float magicSmartFunnyNumber = 0.0;

	// sum up all priorities and count the tasks
	for (int i = 0; i < MAX_TASKS; i++) {

		if (_tasks[i] != NULL) {

			prioritySum += _tasks[i]->priority;
			taskSum++;
		}
	}

	// calculate the magicSmartFunnyNumber
	magicSmartFunnyNumber = (float)(rand_() % RAND_MAX ) / RAND_MAX;

	// who is the winner? (we do the second loop for the anti-performance thing)
	for (int task = 0; task < MAX_TASKS; task++) {

		if (_tasks[task] != NULL) {

			level += ((float)_tasks[task]->priority / (float)prioritySum);
			if (level >= magicSmartFunnyNumber) {

				activeTask = task;
				return;
			}
		}
	}

	// if we reach this line - all is over :(
	// was joking - just take the same task again :)
	// but this should never happen!
	 /*
	 while (_tasks[++activeTask % MAX_TASKS] == NULL) { }
	 activeTask = activeTask % MAX_TASKS;
	 */
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
