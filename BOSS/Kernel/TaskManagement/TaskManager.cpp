#include "TaskManager.h"
TaskManager* tmanager;

//#pragma INTERRUPT (SWI) ;

void swift()  {
	tmanager->scheduleTask();
}


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

	// add Task to list
	_tasks.push_back(task);

	return task->id;
}

/**
 * deleteTask
 * removes a existings Task from the ProcessList
 */
 int TaskManager::deleteTask(TID_t id) {
 	
 	// TODO: implement delete Task
 	return 0;
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
  * scheduleTask
  * starts the task which is next in row
  */
int TaskManager::scheduleTask() {
 	
 	// get index of next task
 	Task* nextTask = _scheduler->getNextTask(_tasks);
 	
 	// if there is no Task (loading)
 	if (_activeTask == NULL) {
 		
 		// execute next thread
 		_activeTask = nextTask;
 		_activeTask->status = Running;
 		_activeTask->initAddr();	
 		
 	// check if this task is not already running
 	
 	// HACK == =>>> back to !=
	} else if (_activeTask->id == nextTask->id) {
 		
 		// TODO: disable HW-Interrupts
 		
 		// set active Task to ready
 		_activeTask->status = Ready;
 		save(registers);
 		
 		// execute next thread
 		_activeTask = nextTask;
 		
 		_activeTask->status = Running;
 		//_activeTask->initAddr();
 		load(registers);	
 		
 		// TODO: enable HW-Interrupts
 	
 	// continue the active Task
 	} else {
 		
		/* Return from the interrupt. If a context 
		switch has occurred this will return to a 
		different task. */ 
		//asm ( " RET " ); 
 		
 		// do nothing it will go automatically back to the running function
 		return 0;
 	}

	// if a task is finished goto the next one
	// TODO: delete finished Task by TID
	_tasks.pop_front();
//	_activeTask = NULL;
	scheduleTask();
 	return 0;
 }

TaskManager::~TaskManager()
{
}
