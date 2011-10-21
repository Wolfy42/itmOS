#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <list>
#include "Task/Task.h"
#include "Scheduler/Scheduler.h"

using namespace std;

class TaskManager {
public:
	TaskManager();
	virtual ~TaskManager();
	
	// create a new Task
	TID_t createTask(void(*function)(void));
	
	// deletes an existing Task
	int deleteTask(TID_t id);
	
	// schedules the next task
	int scheduleTask();
	
	// getter/setter
	list<Task*> getTasks() const { return _tasks; }
	
	Scheduler* getScheduler() const { return _scheduler; }
	void setScheduler(Scheduler* scheduler) { _scheduler = scheduler; }
	
	Task* getActiveTask() const { return _activeTask; }
	void setActiveTask(Task* activeTask) { _activeTask = activeTask; }
	
private:
	// list of all tasks waiting to be executed
	list<Task*> _tasks;
	
	// Scheduler for deciding, which task is the CHOSEN ONE
	Scheduler* _scheduler;
	
	// this is the active Task - we need to save for later reuse
	Task* _activeTask;
};

#endif /*TASKMANAGER_H_*/
