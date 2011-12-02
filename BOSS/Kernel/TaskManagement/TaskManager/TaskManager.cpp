
#include "TaskManager.h"

TaskManager::TaskManager() {}

TaskManager::~TaskManager() {}

void TaskManager::killTask(int taskId) {
	
	_tasks[taskId]->status = Dead;
}

void TaskManager::suspendCurrentTask()  {
	_tasks[activeTask]->priority = 0;
}

void TaskManager::highPriorityForTask(int taskId)  {

	//TODO: change this
	for (int i = 0; i < MAX_TASKS; i++)  {

		if (_tasks[i] != NULL)  {
			_tasks[i]->priority = 50;
		}
	}
}
