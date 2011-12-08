#ifndef SYSTEMCALLEXEC_H_
#define SYSTEMCALLEXEC_H_

#include "Kernel/Kernel.h"
#include "Kernel/Task/TaskManager.h"

class SystemCallExec
{
	private:
		Kernel* _kernel;
		TaskManager* _taskmanager;
		
	public:
		SystemCallExec(Kernel* kernel, TaskManager* taskmanager);
		virtual ~SystemCallExec();
		
		// returns true if context switch is needed
		// does SystemCall Action
		bool execute(int swiNumber, int* parameters);
};

#endif /*SYSTEMCALLEXEC_H_*/
