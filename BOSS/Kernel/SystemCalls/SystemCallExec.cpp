#include "Kernel/Task/Semaphore.h"
#include "SystemCallExec.h"

SystemCallExec::SystemCallExec(Kernel* kernel, TaskManager* taskmanager) {
	_kernel = kernel;
	_taskmanager = taskmanager;
}

SystemCallExec::~SystemCallExec()
{
}

bool SystemCallExec::semaphore(bool exit, int semaphoreType, int id) {
    Task* target = NULL;
    bool switchTask = false;
    switch (semaphoreType) {
        case SEMAPHORE_OWN_MESAGE_QUEUE:
            target = _taskmanager->getActiveTask();
            break;
        case SEMAPHORE_SERVICE_MESSAGE_QUEUE:
            target = _kernel->getServiceManager()->getTaskForService(id);
            break;
        case SEMAPHORE_TASK_MESSAGE_QUEUE:
            target = _taskmanager->getTaskFor(id);
            break;
        default:
            break;
    }
    if (!exit) {
        switchTask = !(target->semaphore->enter(_taskmanager->getActiveTask()));
    } else {
        target->semaphore->exit();
    }
    return switchTask;
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
        case SEMAPHORE:
            switchTask = semaphore(params[2], params[3], params[4]);
            
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
