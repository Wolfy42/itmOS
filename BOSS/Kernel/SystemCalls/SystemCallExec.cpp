
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
bool SystemCallExec::execute(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7)  {
    bool switchTask = false;
    int* params = new int[7];
    params[0] = para1;
    params[1] = para2;
    params[2] = para3;
    params[3] = para4;
    params[4] = para5;
    params[5] = para6;
    params[6] = para7;

//    swiNumber = SUSPEND;

	switch (swiNumber) {

    	case WRITE:
    		_kernel->write(params);
    		break;
    	case WRITE_RESPONE:
    		//TODO: write the response from a service to a task
    		break;
    	case SUSPEND:

//    		int paramsTest[4];
//    		paramsTest[0] = LED_SERVICE_ID;
//    		paramsTest[1] = 2;
//    		paramsTest[2] = 0;
//    		paramsTest[3] = 0;
//    		_kernel->write(paramsTest);
    		//TODO: suspend a task

    		_taskmanager->getActiveTask()->status = Blocked;
    		break;

        case EXIT:
         	_taskmanager->kill(para1);
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
	delete params;
    return switchTask;
}
