
#include "TaskManager.h"

TaskManager::TaskManager() {}

TaskManager::~TaskManager() {}

Task* TaskManager::getTaskFor(int taskId)  {

	//TODO: return a task
	return NULL;
}

void TaskManager::block(int taskId)  {

}

void TaskManager::unblock(int taskId)  {

}

void TaskManager::killTask(int taskId) {
	
	_tasks[taskId]->status = Dead;
}

void TaskManager::suspendCurrentTask()  {
	_tasks[activeTask]->priority = 0;
}
