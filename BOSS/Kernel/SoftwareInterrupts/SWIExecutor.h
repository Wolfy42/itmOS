
#ifndef SWIEXECUTOR_H_
#define SWIEXECUTOR_H_

#include "Kernel/Kernel.h"
#include "Kernel/TaskManagement/TaskManager/TaskManager.h"
#include "BOSSAPI/systemCalls.h"


class SWIExecutor {
	Kernel* _kernel;
	TaskManager* _taskmanager;

public:
	SWIExecutor(Kernel* kernel, TaskManager* taskmanager);
	virtual ~SWIExecutor();

	void executeSWI(int swiNumber, int* parameters);
};

#endif /* SWIEXECUTOR_H_ */
