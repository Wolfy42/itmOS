#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <list>

#include "Task/Task.h"
#include "Scheduler/Scheduler.h"

class TaskManager
{
public:
	TaskManager();
	virtual ~TaskManager();
	
	// create a new Task
	TID_t createTask(void(*function)(void));
	
	// deletes an existing Task
	int deleteTask(TID_t id);
	
	// schedules the next task
	int scheduleTask();
	
private:
	// list of all tasks waiting to be executed
	std::list<Task*> tasks;
	
	// Scheduler for deciding, which task is the CHOSEN ONE
	Scheduler* scheduler;
};

#endif /*TASKMANAGER_H_*/
