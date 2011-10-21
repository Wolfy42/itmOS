#include "TaskManager.h"

TaskManager::TaskManager()
{
	
	scheduler = new Scheduler();
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
	Task* newTask = new Task();
	newTask->id = tasks.size();
	newTask->status = Ready;
	newTask->priority = 100;
	newTask->execute = function;

	// add Task to list
	tasks.push_back(newTask);

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
 	Task* newTask = scheduler->getNextTask(tasks);
 	
 	// if there is no Task (loading)
 	if (activeTask == NULL) {
 		
 		// execute next thread
 		activeTask = newTask;
 		activeTask->status = Running;
 		activeTask->execute();	
 		
 	// check if this task is not already running
	} else if (activeTask->id != newTask->id) {
 		
 		// TODO: disable HW-Interrupts
 		
 		
 		// set active Task to ready
 		activeTask->status = Ready;
 		
 		// TODO: save current execution state
 		
 		
 		// execute next thread
 		activeTask = newTask;
 		activeTask->status = Running;
 		activeTask->execute();	
 		
 		// TODO: enable HW-Interrupts
 	
 	// continue the active Task
 	} else {
 		// TODO: execute is not enough
 		activeTask->execute();	
 	}
 	
	// if a task is finished goto the next one
	// TODO: delete finished Task
	scheduleTask();

 	return 0;
 }

TaskManager::~TaskManager()
{
}
