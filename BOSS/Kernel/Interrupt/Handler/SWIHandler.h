#ifndef SWIEXECUTOR_H_
#define SWIEXECUTOR_H_

#include "Kernel/SystemCalls/SystemCallExec.h"

class SWIHandler {
private:
	SystemCallExec* _sysCallExec;

public:
	SWIHandler(SystemCallExec* sysCallExec);
	virtual ~SWIHandler();

	// returns true if context switch is needed
	bool handle(int swiNumber, int* parameters);
};

#endif /* SWIEXECUTOR_H_ */
