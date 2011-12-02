
#include "SWIExecutor.h"

SWIExecutor::SWIExecutor(Kernel* kernel, TaskManager* taskmanager) {
	_kernel = kernel;
	_taskmanager = taskmanager;
}
SWIExecutor::~SWIExecutor() {}

void SWIExecutor::executeSWI(int swiNumber, int* parameters)  {

    switch (swiNumber) {

    	case SUSPEND:
        	_taskmanager->suspendCurrentTask();
        	break;
    	case WRITE:
    		_kernel->write(parameters);

    		//TODO: should work with service-id
    		_taskmanager->highPriorityForTask(0);
    		break;

         case EXIT:
         	_taskmanager->killTask(parameters[0]);
            break;
        case KILL:
            break;
        case EXEC:
            break;
        case FORK:
            break;
        case YIELD:
            break;
        default:
            break;
    }
}
