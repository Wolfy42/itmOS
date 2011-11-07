#include "TaskManager.h"

// *** globals ***

#define OTHERWISE else

// global variables
asm("\t .bss _registers, 64");
asm("\t .global _registers");
asm("\t .bss _kernelRegisters, 64");
asm("\t .global _kernelRegisters");
asm("\t .bss _returnAddress, 4");
asm("\t .global _returnAddress");
asm("\t .bss _hasStarted, 4");
asm("\t .global _hasStarted");

class TaskManager;
TaskManager* globalTaskManager;

// *** globals end ***



// this is an interrupt and therefore it has to be c 
// so this is not par of the Class Taskmanager
//// same code in schedule();
//#pragma TASK
//#pragma INTERRUPT (SWI) ;
//extern "C" void c_intSWI()  {
//	
//	if (hasStarted == 0) {
//		hasStarted = 1;
//	} else {
//		// save the return address of interrupt == pc of task
//		asm("\t PUSH {r0}");
//		asm("\t LDR r0, returnAddress_a");
//		asm("\t STR lr, [r0, #0]");
//		asm("\t POP {r0}");
//	
//		// save registers of app mode task
//		asm("\t PUSH {r14}");
//		asm("\t LDR r14, registers_a");
//		asm("\t STM r14, {r0-r14}^");
//		asm("\t POP {r14}");
//		
//		// load the registers (includeing sp) from kernel - so we can use the scheduler and tcbs.
//		asm("\t LDR r0, kernelRegisters_a");
//		asm("\t LDM r0, {r0-r14}");
//
//		// TODO: where the fkn hell is r0?	
//	}
//
//	
//
//	// *** taskmanager stuff ***
//	
//	// get next Task
//	Task* nextTask = globalTaskManager->getScheduler()->getNextTask(globalTaskManager->getTasks(), globalTaskManager->getActiveTask()->id);
//		
//	// if its not the same task --> context switch
//
//	// save registers of previous task
//	int i = 0;
//	while (i < 15) {
//		globalTaskManager->getActiveTask()->registers[i] = registers[i];
//		i++;
//	}
//	// save register #15 which is PC / save program counter of task (lr of interrupt)
//	globalTaskManager->getActiveTask()->registers[15] = returnAddress;
//
//	// set new active task
//	globalTaskManager->setActiveTask(nextTask);
//	
//	// load new registers
//	i = 0;
//	while (i < 15) {
//		registers[i] = nextTask->registers[i];
//		i++;
//	}
//	// set returnAddress
//	returnAddress = nextTask->returnAddress;
//	
//	// save kernel stack
//	asm("\t LDR r0, kernelRegisters_a");
//	asm("\t STM r0, {r0-r14}");
//	
//	// set new returnAddress of the IRQ thing
//	asm("\t LDR r0, returnAddress_a");
//	asm("\t LDR r0, [r0, #0]");
//	asm("\t MOV lr, r0");
//	
//	// load new registers in assembler and jump over there
//	asm("\t LDR r0, registers_a");
//	asm("\t LDM r0, {r0-r14}^");
//
//}


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
	
	// alloc some fields
	asm("registers_a .field _registers, 32");
	asm("kernelRegisters_a .field _kernelRegisters, 32");
	asm("returnAddress_a .field _returnAddress, 32");
	asm("hasStarted_a .field _hasStarted, 32");
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
 		_activeTask = _scheduler->getNextTask(_tasks, _activeTask->id);
		if (_activeTask == NULL) {
			
			// TODO: SYSTEM ERROR
			// or just wait :)
		} else { 
			
			// load new registers
			for (int q = 0; q < 16; q++) {
				registers[q] = _activeTask->registers[q];
			}
			//*registers = *(_activeTask->registers);
			
			// save kernel stack
			asm("\t LDR r0, kernelRegisters_a");
			asm("\t STM r0, {r0-r14}");
			
			// load new registers in assembler and jump over there
			asm("\t LDR r0, registers_a");
			asm("\t LDR r1, [r0, #52]");
			asm("\t LDR r2, [r0, #60]");
			asm("\t MOV sp, r1");
			asm("\t MOV pc, r2");
			//asm("\t LDM r0, {r0-r14}^");
		}
		
		
		// load the registers (includeing sp) from kernel - so we can use the scheduler and tcbs.
		asm("\t LDR r0, kernelRegisters_a");
		asm("\t LDM r0, {r0-r14}");
		
		
		// there are two reasons why we are here:
			// 1. no Task running at all
			// 2. the Task has finished and is ready to die
		if (_activeTask != NULL) {
		

			deleteTask(_activeTask);
			//_activeTask = _scheduler->getNextTask(_tasks, _activeTask->id);	

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
