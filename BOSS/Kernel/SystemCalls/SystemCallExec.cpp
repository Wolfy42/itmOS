#include "SystemCallExec.h"

#include "BOSSAPI/systemCalls.h"

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
bool SystemCallExec::execute(int swiNumber, int* parameters)  {
    switch (swiNumber) {
 //   	case READ:

    	case WRITE:
    		_kernel->write(parameters);
    		break;

         case EXIT:
         	_taskmanager->kill(parameters[0]);
         	// context switch
        	return true;
        	
        case KILL:
            break;
        case EXEC:
            break;
        case FORK:
            break;
        case YIELD:
        	// just context switch
        	return true;
 //       case SERVICE_CALL:
        	//_kernel->callService(parameters);
            break;
 //       case SERVICE_RESPONSE:
            break;
        default:
            break;
    }
}
