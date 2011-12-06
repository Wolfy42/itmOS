#include "TaskManager.h"

#include "Lib/Rand.h"
#include "TaskRoutines.h"

// needed for NULL :P
#include <stdio.h>
// needed for RAND_MAX o_O
#include <stdlib.h>

/*
 * 	Constructor inits member variables and TaskRoutines
 */
TaskManager::TaskManager() {

	// init TaskRoutines
	initTaskRoutines(this);
	
	// set initial active Task
	_activeTask = 0;

	// set all task entries to NULL
	int i = 0;
	for (i = 0; i < MAX_TASKS; i++) {
	
		_tasks[i] = NULL;	
	}	
}

/*
 * Destructor
 */
TaskManager::~TaskManager() {}


/*
 * 	return a Task Struct/Object for a task ID (TID_t)
 */
Task* TaskManager::getTaskFor(int taskId)  {

	return _tasks[taskId];
}

/*
 *	get the Active Task as Struct/Object
 */
Task* TaskManager::getActiveTask() {
	
	return _tasks[_activeTask];
}

/*
 *	get whole Task list
 */
Task** TaskManager::getTaskList() {
	
	return _tasks;
}


/*
 * 	creates a new Task with
 * 	- name
 * 	- priority (0 - 100)
 * 	- initial Address Point
 */
TID_t TaskManager::create(char* name, int priority, int initAddress, bool blockParent) {

	int nextTask = getNextFreeSlot();

	// no empty slot: return nextTask (which should be error number)
	if (nextTask == -1) {
		return nextTask;
	}

	// init task
	Task* t = new Task();
	t->id = nextTask;
	t->name = name;
	t->status = Ready;
	t->child = NULL;
	t->parent = NULL;
	
	if (blockParent == true) {
	
		t->parent = getActiveTask();
		getActiveTask()->child = t;	
	}

	// to ensure a valid priority
	if (priority < 0) {
		t->priority = 0;
	} else if (priority > 100) {
		t->priority = 100;
	} else {
		t->priority = priority;
	}

	// init Task Control Block
	t->tcb.restartAddress = initAddress;
	t->tcb.R13 = 0x820E0000 + (nextTask + 1) * 0x00010000;
	t->tcb.CPSR = 0x80000110;
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
	t->tcb.R14 = (int)exitTask;

	// add Task
	_tasks[nextTask] = t;

	// return TaskID
	return t->id;
}
	


/*
 * 	delete Task
 * 	- deletes Task now instantly
 */
void TaskManager::kill(int taskId) {
	
	// release parent
	if (_tasks[taskId]->parent != NULL) {
	
		if (_tasks[taskId]->parent->status == Blocked) {
		
			_tasks[taskId]->parent->status = Ready;
		}
	}
	
	// kill child
	if (_tasks[taskId]->child != NULL) {
	
		kill(_tasks[taskId]->child->id);
	}
	
	delete _tasks[taskId];
	_tasks[taskId] = NULL;
}



/*
 * 	schedule
 * 	- changes the _activeTask member to the TID of the next Task
 * 
 * 	ADDITION INFORMATION:
 * ---------------------------------------------------------
 *	SteMar-Scheduler v0.2gamma (Stefan & Martin)
 *
 *	The Scheduler schedules tasks by using its
 *	priorities and a smart/funny/magic randomizer.
 *	Also the performance is funny - but what shells?
 *
 *	Don't try to understand the code - i don't understand it either!
 * 	ITS MAGIC!
 *
 *	This scheduler is licensed under the SMNPL
 *	(StefanMartinNotPublicLicense)
 *
 *	CAUTION: THIS SCHEDULER MAY HARM YOUR BOARD!
 *
 *	If your board is destroyed don't call us - WE CALL YOU!
 * ---------------------------------------------------------
 */
void TaskManager::schedule() {
	
	int prioritySum = 0;
	int taskSum = 0;
	float level = 0.0;
	float magicSmartFunnyNumber = 0.0;
	
	// sum up all priorities and count the tasks
	for (int i = 0; i < MAX_TASKS; i++) {
	
		if (_tasks[i] != NULL) {
	
			// sum up the priorities of Ready Tasks
			if (_tasks[i]->status == Ready) {
				prioritySum += _tasks[i]->priority;
				taskSum++;
			}
		}
	}
	
	// calculate the magicSmartFunnyNumber
	magicSmartFunnyNumber = (float)(rand_() % RAND_MAX ) / RAND_MAX;
	
	// who is the winner? (we do the second loop for the anti-performance thing)
	for (int task = 0; task < MAX_TASKS; task++) {
	
		if (_tasks[task] != NULL) {
	
			level += ((float)_tasks[task]->priority / (float)prioritySum);
			if (level >= magicSmartFunnyNumber) {
	
				_activeTask = task;
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


/*
 * getNextFreeSlot of _tasks array
 */
int TaskManager::getNextFreeSlot() {

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

