
#ifndef SWIEXECUTOR_H_
#define SWIEXECUTOR_H_

#include "Kernel/Kernel.h"
#include "BOSSAPI/systemCalls.h"

class SWIExecutor {
	Kernel* _kernel;

public:
	SWIExecutor(Kernel* kernel);
	virtual ~SWIExecutor();

	void executeSWI(int swiNumber, int* parameters);
};

#endif /* SWIEXECUTOR_H_ */
