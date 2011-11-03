#include "TaskManager.h"

// global variables
asm("\t .bss _stackPointer, 4");
asm("\t .global _stackPointer");
asm("\t .bss _funcPointer, 4");
asm("\t .global _funcPointer");
asm("\t .bss _kernelStackPointer, 4");
asm("\t .global _kernelStackPointer");

#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI()  {

//	save(registers);
}


/**
 * Constructor
 */
TaskManager::TaskManager() {
	_scheduler = new Scheduler();
	_activeTask = NULL;

	// initialize task ids
	for (int i = 0; i < MAX_TASKS; i++) {
		_tids[i] = 0;
	}
	
	// alloc some fields
	asm("stackPointer_a .field _stackPointer, 32");
  	asm("funcPointer_a .field _funcPointer, 32");
  	asm("kernelStackPointer_a .field _kernelStackPointer, 32");
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
		task = new Task(tid, name);
		task->status = Ready;
		task->priority = 100;
		task->initAddr = function;
		//task->stackPointer = 0x82000000;
	
		// add Task to list
		_tasks.push_back(task);
		
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
int TaskManager::deleteTask(TID_t tid) {

	// remove it from the list and from the tids array
	for (std::list<Task*>::const_iterator iterator = _tasks.begin(); iterator != _tasks.end(); ++iterator) {
		if ( (*iterator)->id == tid ) {
			_tasks.remove(*iterator);
			_tids[(*iterator)->id - 1] = 0;
			return 0;
		}
	}
 	
	return -1;
}

/**
 * showTasks
 * shows all running tasks
 */
void TaskManager::showTasks() {

	for (std::list<Task*>::const_iterator iterator = _tasks.begin(); iterator != _tasks.end(); ++iterator) {
		printf("%d\t\t%s", (*iterator)->id, (*iterator)->name);
	}

}
 
/*
 * schedule
 * this routine should be called by the IRQ?
 * 
 */
void TaskManager::schedule() {
	
	// SAVEREG
		// this -> save register in active stack
		
	// change stack to main stack
	
	// check if its different task
		// do this with scheduler
	
	// if it is different load
	
		// change stack to new active stack
		// LOADREG
	
	// else if its the same:
		// RETURN to return-address	


	// save active register
	if (_activeTask != NULL) {
		
		// save 
	}
	
	// switch to kernel stack
	
	
}

#include <stdio.h>
 /**
  * run
  * run over and over again and try to get new tasks
  * -> lol at this "over and over" comment!
  */
void TaskManager::run() {
 	
 	while (true) {
		if (_activeTask == NULL) {
			
			// TODO: SYSTEM ERROR
			// or just wait :)
		} else {
		
			_activeTask = _scheduler->getNextTask(_tasks);
			
			// first time we start this task
			if (_activeTask->hasBeenStarted == false) {
				
				// save entry point for function
				//funcPointer = (int)_activeTask->initAddr;
				// load stack of task
				//stackPointer = _activeTask->stackPointer;
				
				// first push all register on the stack
				SAVEREG;
				
				// save function Pointer in register 2
				asm("\t LDR r0, funcPointer_a");
    			asm("\t LDR r2, [r0, #0]");
				
				// save kernel stack - load field in r0 - store sp in field 
				asm("\t LDR r0, kernelStackPointer_a");
				asm("\t STR sp, [r0, #0]");
			
				// set new stackpointer to task stackpointer
				asm("\t LDR sp, stackPointer_a");
				
				// set return jump dingens before we fk off
				asm("\t MOV lr, pc");
				// move to r2 - loaded function - RUN
				asm("\t MOV pc, r2");
				
			
			// otherwise return from last point
			} else {
			
				// save my stack pointer
				
				// set the stack pointer of nextTask to active
					// LOAD the register (pop sp)
					
				// run from program counter
			}
		}
		
		
		// change the stack back to the main stack here - because the task is over :)
			// be careful - dont whine about the task stack - task is done anyway
		// just change back to my super duper kernel stack
		asm("\t LDR r0, kernelStackPointer_a");
		// load the value of kernelstackpointer into r1 (otherwise its just address of kernelstackpointer)
		asm("\t LDR r1, [r0, #0]");
		// move the register to the stackpointer - never use LDR for this! y? i dont know.
		asm("\t MOV sp, r1");
		// now load all registers
		LOADREG;
		
		
		// there are two reasons why we are here:
			// 1. no Task running at all
			// 2. the Task has finished and is ready to die
		if (_activeTask != NULL) {
		
			deleteTask(_activeTask->id);
			_activeTask = _scheduler->getNextTask(_tasks);	
		}
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
