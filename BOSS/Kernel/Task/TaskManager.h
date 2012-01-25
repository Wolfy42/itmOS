#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"

/*
 * Change if you wanna hav mor fun (tasks)
 */
#define MAX_TASKS 256

class MMU;




/*
 * 	TaskManager Class
 */
class TaskManager {
private:
	Task* _tasks[MAX_TASKS];
	int _activeTask;
    MMU* _mmu;
    
    int _nrOfTasks;
	
	int getNextFreeSlot();

public:
	TaskManager(MMU* mmu);
	virtual ~TaskManager();

	// get a Task Struct/Object by TaskID (TID_t)
	Task* getTaskFor(int taskId);
	
	// create a new Task
	Task* create(char* name, bool blockParent, int priority = 50);
	
	// delete a Task by TaskID (TID_t)
	void kill(int taskId);
	
	// schedule next Task
	// this means that a method call of schedule changes the _activeTask member
	void schedule();
	
	// get active Task
	Task* getActiveTask();
	
	// get list of all Tasks
	Task** getTaskList();
    
    int getNrOfTasks();
};

#endif /* TASKMANAGER_H_ */
