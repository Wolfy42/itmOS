#include "TaskManager.h"

// *** globals ***

#define OTHERWISE else

// global variables
asm("\t .bss _stackPointer, 4");
asm("\t .global _stackPointer");
asm("\t .bss _funcPointer, 4");
asm("\t .global _funcPointer");
asm("\t .bss _kernelStackPointer, 4");
asm("\t .global _kernelStackPointer");
asm("\t .bss _lrToPcPointer, 4");
asm("\t .global _lrToPcPointer");

class TaskManager;
TaskManager* globalTaskManager;

// *** globals end ***


// this is an interrupt and therefore it has to be c 
// so this is not par of the Class Taskmanager
// same code in schedule();
#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI()  {

	// save return value of swi LR
	asm("\t PUSH {r0}");
	asm("\t LDR r0, lrToPcPointer_a");
	asm("\t STR lr, [r0, #0]");
	asm("\t POP {r0}");
	
	// switch to task (previous) stack (because we are @ swi stack)
	// TODO: swtich stack (SuperUserMode?) - intrinsic
	asm("\t MRS r0, cpsr");
    asm("\t BIC r0, r0, #0x1F  ; CLEAR MODES");
    asm("\t ORR r0, r0, #0x1F  ; SET Super-User MODE");
    asm("\t MSR cpsr_cf, r0");
    // TODO: GOODBYE r0!!!!
	
	// save registers of stack (task stack)
	SAVEREG;
	
	// save stack pointer of task - load field in r0 - store sp in field 
	asm("\t LDR r0, stackPointer_a");
	asm("\t STR sp, [r0, #0]");
	
	// switch to kernel stack
	asm("\t LDR r0, kernelStackPointer_a");
	// load the value of kernelstackpointer into r1 (otherwise its just address of kernelstackpointer)
	asm("\t LDR r1, [r0, #0]");
	// move the register to the stackpointer - never use LDR for this! y? i dont know.
	asm("\t MOV sp, r1");
	// now load all registers
	LOADREG;
	
	// save the task stack
	globalTaskManager->getActiveTask()->stackPointer = stackPointer;
	globalTaskManager->getActiveTask()->returnAddress = lrToPcPointer;
	
	// **** do here some scheduling functions ****
	globalTaskManager->run();
}


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
	asm("stackPointer_a .field _stackPointer, 32");
  	asm("funcPointer_a .field _funcPointer, 32");
  	asm("kernelStackPointer_a .field _kernelStackPointer, 32");
  	asm("lrToPcPointer_a .field _lrToPcPointer, 32");
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
		task = new Task(pos, name);
		task->status = Ready;
		task->priority = 100;
		task->initAddr = function;
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
 
/*
 * schedule
 * this routine should be called by the IRQ?
 * 
 */
void TaskManager::schedule() {
	
	// SAVEREG
		// this -> save register in active stack
		
	// change stack to main stack
	
	// save task stack
	
	// check if its different task
		// do this with scheduler
	
	// save main stack
	
	// if it is different load
	
		// change stack to new active stack
		// LOADREG
	
	// else if its the same:
		// RETURN to return-address	

// code here ---->

	// save return value of swi LR
	asm("\t PUSH {r0}");
	asm("\t LDR r0, lrToPcPointer_a");
	asm("\t STR lr, [r0, #0]");
	asm("\t POP {r0}");
	
	// switch to task (previous) stack (because we are @ swi stack)
	// TODO: swtich stack (SuperUserMode?) - intrinsic
	asm("\t MRS r0, cpsr");
    asm("\t BIC r0, r0, #0x1F  ; CLEAR MODES");
    asm("\t ORR r0, r0, #0x1F  ; SET Super-User MODE");
    asm("\t MSR cpsr_cf, r0");
    // TODO: GOODBYE r0!!!!
	
	// save registers of stack (task stack)
	SAVEREG;
	
	// save stack pointer of task - load field in r0 - store sp in field 
	asm("\t LDR r0, stackPointer_a");
	asm("\t STR sp, [r0, #0]");
	
	// switch to kernel stack
	asm("\t LDR r0, kernelStackPointer_a");
	// load the value of kernelstackpointer into r1 (otherwise its just address of kernelstackpointer)
	asm("\t LDR r1, [r0, #0]");
	// move the register to the stackpointer - never use LDR for this! y? i dont know.
	asm("\t MOV sp, r1");
	// now load all registers
	LOADREG;
	
	// save the task stack
	_activeTask->stackPointer = stackPointer;
	_activeTask->returnAddress = lrToPcPointer;
	
	// **** do here some scheduling functions ****
	run();
	
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
		
			// TODO: avoid code verdoppelung
			
			// first time we start this task
			if (_activeTask->hasBeenStarted == false) {
				
				// now it has been started
				_activeTask->hasBeenStarted = true;
				
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
				// get value of stackpointer - not address
				asm("\t LDR r0, stackPointer_a");
				asm("\t LDR r1, [r0, #0]");
				asm("\t MOV sp, r1");
				
				// set return jump dingens before we fk off
				asm("\t MOV lr, pc");
				// move to r2 - loaded function - RUN
				asm("\t MOV pc, r2");
				
			
			// otherwise return from last point
			} OTHERWISE {
				
				// save entry point for function
				funcPointer = (int)_activeTask->returnAddress;
				// load stack of task
				stackPointer = _activeTask->stackPointer;
				
				// first push all register on the stack
				SAVEREG;
				
				// save function Pointer in register 2
				asm("\t LDR r0, funcPointer_a");
    			asm("\t LDR r2, [r0, #0]");
				
				// save kernel stack - load field in r0 - store sp in field 
				asm("\t LDR r0, kernelStackPointer_a");
				asm("\t STR sp, [r0, #0]");
			
				// set new stackpointer to task stackpointer
				// get value of stackpointer - not address
				asm("\t LDR r0, stackPointer_a");
				asm("\t LDR r1, [r0, #0]");
				asm("\t MOV sp, r1");
				
				// load all register of new task
				LOADREG;
				
				// set return jump dingens before we fk off
				asm("\t MOV lr, pc");
				// move to r2 - loaded function - RUN
				asm("\t MOV pc, r2");
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
