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
	
	
	// TODO: setstatus to READY;
	return -1;
}

/**
 * deleteTask
 * removes a existings Task from the ProcessList
 */
 int TaskManager::deleteTask(TID_t id) {
 	
 	return 0;	
 }
 
 /**
  * scheduleTask
  * starts the task which is next in row
  */
 int scheduleTask() {
 	
 	// asks the scheduler for the next Task
 	
 	// starts the Task with the given TID
 	return 0;
 }

TaskManager::~TaskManager()
{
}
