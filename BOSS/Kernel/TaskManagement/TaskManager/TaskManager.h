
#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Kernel/TaskManagement/Tasks.h"

class TaskManager {

public:
	TaskManager();
	virtual ~TaskManager();

	Task* getTaskFor(int TaskId);
};

#endif /* TASKMANAGER_H_ */
