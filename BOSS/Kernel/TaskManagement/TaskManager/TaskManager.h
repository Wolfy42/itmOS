
#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Kernel/TaskManagement/Tasks.h"

class TaskManager {

public:
	TaskManager();
	virtual ~TaskManager();

	Task* getTaskFor(int taskId);
	void block(int taskId);
	void unblock(int taskId);
	
	void killTask(int taskId);
};

#endif /* TASKMANAGER_H_ */
