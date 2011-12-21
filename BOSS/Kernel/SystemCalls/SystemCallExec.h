#ifndef SYSTEMCALLEXEC_H_
#define SYSTEMCALLEXEC_H_

#include "Kernel/Kernel.h"
#include "Kernel/Task/TaskManager.h"
#include "API/systemCalls.h"

class Kernel;

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
		bool execute(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7);
};

#endif /*SYSTEMCALLEXEC_H_*/
