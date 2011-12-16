#ifndef SWIEXECUTOR_H_
#define SWIEXECUTOR_H_

#include "Kernel/SystemCalls/SystemCallExec.h"

// Forward-declaration
class SystemCallExec;

class SWIHandler {
	private:
		SystemCallExec* _sysCallExec;
	
	public:
		SWIHandler(SystemCallExec* sysCallExec);
		virtual ~SWIHandler();
	
		// returns true if context switch is needed
		bool handle(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7);
};

#endif /* SWIEXECUTOR_H_ */
