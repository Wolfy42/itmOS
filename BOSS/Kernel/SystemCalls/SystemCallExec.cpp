#include "SystemCallExec.h"

#include "API/systemCalls.h"

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
bool SystemCallExec::execute(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7)  {
    switch (swiNumber) {

    	case WRITE:
    		//TODO: write the parameters into the messageQueue of a Service
//    		_kernel->write(parameters);
    		break;
    	case WRITE_RESPONE:
    		//TODO: write the response from a service to a task
    		break;
        case EXIT:
         	_taskmanager->kill(para1);
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
    }
    return false;
}
