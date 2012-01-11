
#include "SystemCallExec.h"

SystemCallExec::SystemCallExec(Kernel* kernel, TaskManager* taskmanager) {
	_kernel = kernel;
	_taskmanager = taskmanager;
}

SystemCallExec::~SystemCallExec()
{
}

/*
 * 	execute Sys Calls
 */
bool SystemCallExec::execute(int swiNumber, int params[])  {
    bool switchTask = false;

	switch (swiNumber) {

    	case WRITE:
    		_kernel->write(params);
    		break;
    	case WRITE_RESPONSE:
    		_kernel->writeResponse(params);
    		break;
    	case SUSPEND:

    		_taskmanager->getActiveTask()->status = Blocked;
    		break;

        case EXIT:
         	_taskmanager->kill(params[1]);
         	// context switch
         	switchTask = true;
         	break;
        	
        case KILL:
            break;
        case EXEC:
            break;
        case FORK:
            break;
        case YIELD:
        	// just context switch
        	switchTask = true;
        	break;
    }
    return switchTask;
}
