#include "TaskManager.h"
TaskManager* tmanager;

//#pragma INTERRUPT (SWI) ;

#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI()  {

	save(registers);
}


// save stackpointer
asm("\t .bss _stackPointer, 64");
asm("\t .global _stackPointer");


TaskManager::TaskManager()
{
	_scheduler = new Scheduler();
	_activeTask = NULL;
	tmanager = this;
}

/**
 * createTask
 * creates a new Task and sets it status to READY
 */
TID_t TaskManager::createTask(void(*function)(void)) {
	
	// create new Task
	Task* task = new Task();
	task->id = _tasks.size();
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

	return task->id;
}

/**
 * deleteTask
 * removes a existings Task from the ProcessList
 */
int TaskManager::deleteTask(Task* task) {
 	
 	// TODO: implement delete Task
 	delete task;
 	return 0;
}
 
/*
 * 
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

}

 /**
  * HILFE HILFE C-Funktion 
  *
  *
  */
asm("\t .bss _registers, 64");
asm("\t .global _registers");
void save(int* regs) {
	
	asm("\t STR r0, [sp, #0]");
	asm("\t STR r1, [sp, #4]");
	asm("\t STR r2, [sp, #8]");
	asm("\t STR r3, [sp, #12]");
	asm("\t STR r4, [sp, #16]");
	asm("\t STR r5, [sp, #20]");
	asm("\t STR r6, [sp, #24]");
	asm("\t STR r7, [sp, #28]");
	asm("\t STR r8, [sp, #32]");
	asm("\t STR r9, [sp, #36]");
	asm("\t STR r10, [sp, #40]");
	asm("\t STR r11, [sp, #44]");
	asm("\t STR r12, [sp, #48]");
	asm("\t STR sp, [r0, #0]");
	asm("\t ADD r0, r0, #8");
	asm("\t STR r0, [sp, #52]");
	asm("\t LDR r0, [sp, #0]");
	asm("\t STR lr, [sp, #56]");
	//asm("\t STR pc, [pc, #60]");
}

void load(int* regs) {
	asm("\t LDR r0, [sp, #0]");
	asm("\t LDR r1, [sp, #4]");
	asm("\t LDR r2, [sp, #8]");
	asm("\t LDR r3, [sp, #12]");
	asm("\t LDR r4, [sp, #16]");
	asm("\t LDR r5, [sp, #20]");
	asm("\t LDR r6, [sp, #24]");
	asm("\t LDR r7, [sp, #28]");
	asm("\t LDR r8, [sp, #32]");
	asm("\t LDR r9, [sp, #36]");
	asm("\t LDR r10, [sp, #40]");
	asm("\t LDR r11, [sp, #44]");
	asm("\t LDR r12, [sp, #48]");
	asm("\t LDR sp, [sp, #52]");
	asm("\t LDR lr, [sp, #56]");

	asm("\t MOV pc, lr");
}

 /**
  * run
  * run over and over again and try to get new tasks
  */
void TaskManager::run() {
 	
 	while (true) {
		if (_activeTask == NULL) {
			
			// TODO: SYSTEM ERROR
			// or just wait :)
		} else {
		
			_activeTask = _scheduler->getNextTask(_tasks);
			
			// first time we start this task
			if (_activeTask->stackPointer == 0) {
				
				// run it from the beginning
				_activeTask->initAddr();
			
			// otherwise return from last point
			} else {
			
				// save my stack pointer
				
				// set the stack pointer of nextTask to active
					// LOAD the register (pop sp)
					
				// run from program counter
			}
		}
		
		// there are two reasons why we are here:
			// 1. no Task running at all
			// 2. the Task has finished and is ready to die
		if (_activeTask != NULL) {
		
			deleteTask(_activeTask);
			_activeTask = NULL;	
		}
 	}
}

TaskManager::~TaskManager()
{
}
