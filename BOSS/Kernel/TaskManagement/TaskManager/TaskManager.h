
#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Kernel/TaskManagement/Tasks.h"

class TaskManager {

public:
	TaskManager();
	virtual ~TaskManager();

	void killTask(int taskId);
	void suspendCurrentTask();
	void highPriorityForTask(int taskId);
};

#endif /* TASKMANAGER_H_ */
