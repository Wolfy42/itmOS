#include "TaskManager.h"

// *** globals ***

#define OTHERWISE else

// global variables
asm("\t .bss _registers, 64");
asm("\t .global _registers");
asm("\t .bss _returnAddress, 4");
asm("\t .global _returnAddress");

class TaskManager;
TaskManager* globalTaskManager;

// *** globals end ***

// this is an interrupt and therefore it has to be c 
// so this is not par of the Class Taskmanager

#pragma TASK
#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI()  {

	//TODO: r0 is lost...

	asm("\t LDR r0, registers_a");
	asm("\t STM r0, {r0-r14}^");

	asm("\t LDR r0, returnAddress_a");
	asm("\t STR lr, [r0, #0]");
	// save registers of previous task
	for (int i=0; i<15; i++) {
		globalTaskManager->getActiveTask()->registers[i] = registers[i];
	}
	// save register #15 which is PC / save program counter of task (lr of interrupt)
	globalTaskManager->getActiveTask()->registers[15] = returnAddress;

	/*
	 *
	 * Do some interrupt handling?
	 *
	 */

	// get next Task
	Task* nextTask = globalTaskManager->getScheduler()->getNextTask(globalTaskManager->getTasks(), globalTaskManager->getActiveTask()->id);

	// set new active task
	globalTaskManager->setActiveTask(nextTask);
	
	// load new registers
	for (int i=0; i<15; i++) {
		registers[i] = nextTask->registers[i];
	}
	// set returnAddress
	returnAddress = nextTask->registers[15];
	
	// load new registers in assembler and jump over there
	asm("\t LDR r0, registers_a");
	asm("\t LDM r0, {r0-r14}^");
	
	//Back to User mode
	asm("\t CPS 0x10");

	// set the PC to the Task-PC
	asm("\t LDR r0, returnAddress_a");
	asm("\t LDR r0, [r0, #0]");
	asm("\t MOV pc, r0");
}

// alloc some fields
asm("registers_a .field _registers, 32");
asm("returnAddress_a .field _returnAddress, 32");

/**
 * Constructor
 */
TaskManager::TaskManager() {
	_scheduler = new Scheduler();
	_activeTask = NULL;
	globalTaskManager = this;
	pos = 0;

	// initialize task ids
	for (int i = 0; i < MAX_TASKS; i++) {
		_tids[i] = 0;
	}
}

/**
 * createTask
 * creates a new Task and sets it status to READY
 */
Task* TaskManager::createTask(std::string name, void(*function)(void)) {
	
	Task* task = NULL;
	TID_t tid = getNextTaskID();

	// check if there is a free task id -> lol should never happen!
	if (tid > 0) {
		// create new Task
		task = new Task(pos, name, function);
		task->status = Ready;
		task->priority = 100;
		//task->stackPointer = 0x82000000;
	
		// add Task to list
		_tasks[pos] = task;
		pos++;
		
		// if there is no task - run it right now
		if (_activeTask == NULL) {

			_activeTask = task;
		}
	}

	return task;
}

/**
 * deleteTask
 * removes a existings Task from the ProcessList
 */
int TaskManager::deleteTask(Task* task) {

	// remove it from the list and from the tids array

	delete _tasks[task->id];
	return -1;
}

/**
 * showTasks
 * shows all running tasks
 */
void TaskManager::showTasks() {



}


 /**
  * run
  * run over and over again and try to get new tasks
  * -> lol at this "over and over" comment!
  */
void TaskManager::run() {
 	
 	while (true) {
 		// idle-Task?
 	}
}

/*
 * returns the next task ID or -1 if there is no free TID available (lol :=)
 */
TID_t TaskManager::getNextTaskID() {

	for (int i = 0; i < MAX_TASKS; i++) {
		if (_tids[i] == 0) {
			_tids[i] = 1;
			return i + 1;
		}
	}

	// too many tasks are already inserted
	return -1;
}

TaskManager::~TaskManager(){

	delete _scheduler;
	delete [] _tids;
}
