#include "TaskManager.h"


TaskManager::TaskManager()
{
	_scheduler = new Scheduler();
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
	} else if (_activeTask->id != nextTask->id) {
 		
 		// TODO: disable HW-Interrupts
 		
 		
 		// set active Task to ready
 		_activeTask->status = Ready;
 		
 	//	saveContext(_activeTask->registers);
 		// TODO: save current execution state
// 		asm(  
//	 		"    mov r0, #(5 << 5)                        \n"    \
//	        "    msr basepri, r0                            \n" \
//	        ::"i"(i):"r0" 
//        );
		//int value = 0;
		// int gvar;	long long i[32] = {0};
	//	asm("\t load R13, R1");
	//	asm("\t STR R3, [#00x82000000, 0]");
		//asm ("\t mov %0, r0" : "=r"(i));
		//extern int var;
		
//		asm("\t .bss _var,4,4" \
//				"\t .global _var" \
//				"\t mov _var, r0");
// 		

	SAVEREG
	
	LOADREG
	



// 		save_reg();
 		
	//	int j = 0;
		printf("gvar0: %i\n", reg_state[0]);
		printf("gvar1: %i\n", reg_state[1]);

 		// execute next thread
 		_activeTask = nextTask;
 		_activeTask->status = Running;
 		_activeTask->initAddr();	
 		
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
