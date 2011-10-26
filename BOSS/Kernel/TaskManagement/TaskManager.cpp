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
	
	// create a Task Control Block, which is needed by the Task
	TaskControlBlock* newTCB = new TaskControlBlock();
	// TODO: missing TCB properties :)
	
	// create new Task
	Task* task = new Task();
	task->setId(_tasks.size());
	task->setStatus(Ready);
	task->setPriority(100);
	task->execute = function;

	// add Task to list
	_tasks.push_back(task);

	return -1;
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
 		_activeTask->setStatus(Running);
 		_activeTask->execute();	
 		
 	// check if this task is not already running
	} else if (_activeTask->getId() != nextTask->getId()) {
 		
 		// TODO: disable HW-Interrupts
 		
 		
 		// set active Task to ready
 		_activeTask->setStatus(Ready);
 		
 		// TODO: save current execution state
 		
 		
 		// execute next thread
 		_activeTask = nextTask;
 		_activeTask->setStatus(Running);
 		_activeTask->execute();	
 		
 		// TODO: enable HW-Interrupts
 	
 	// continue the active Task
 	} else {
 		// TODO: execute is not enough
 		_activeTask->execute();	
 	}
 	
	// if a task is finished goto the next one
	// TODO: delete finished Task by TID
	_tasks.pop_front();
	scheduleTask();

 	return 0;
 }

TaskManager::~TaskManager()
{
}
