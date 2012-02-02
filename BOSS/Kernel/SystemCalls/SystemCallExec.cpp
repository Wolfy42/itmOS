#include "Kernel/Task/Semaphore.h"
#include "SystemCallExec.h"
#include "Loader/TasksHex/TestBytes.h"
#include "Loader/TasksHex/TestLed1Bytes.h"

SystemCallExec::SystemCallExec(Kernel* kernel, TaskManager* taskmanager) {
	_kernel = kernel;
	_taskmanager = taskmanager;
    for (int i = 0; i < 20; ++i) {
        _waitingTasks[i] = -1;
    }
}

SystemCallExec::~SystemCallExec()
{
}

bool SystemCallExec::semaphore(bool exit, int semaphoreType, int id) {
    Task* target = NULL;
    bool switchTask = false;
    switch (semaphoreType) {
        case SELF:
            target = _taskmanager->getActiveTask();
            break;
        case SERVICE_ID:
            target = _kernel->getServiceManager()->getTaskForService(id);
            break;
        case TASK_ID:
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

void SystemCallExec::notify(int taskOrService, int semaphoreTaskId) {
    Task* semaphoreTask = NULL;
    switch (taskOrService) {
        case SELF:
            semaphoreTask = _taskmanager->getActiveTask();
            break;
        case SERVICE_ID:
            semaphoreTask = _kernel->getServiceManager()->getTaskForService(semaphoreTaskId);
            break;
        case TASK_ID:
            semaphoreTask = _taskmanager->getTaskFor(semaphoreTaskId);
            break;
        default:
            break;
    }
    if (semaphoreTask != NULL) {
        semaphoreTask->semaphore->notifyAll();
    }
}

void SystemCallExec::wait(int taskId, int taskOrService, int semaphoreTaskId) {
    Task* taskToWaitFor = NULL;
    switch (taskOrService) {
        case SELF:
            taskToWaitFor = _taskmanager->getActiveTask();
            break;
        case SERVICE_ID:
            taskToWaitFor = _kernel->getServiceManager()->getTaskForService(semaphoreTaskId);
            break;
        case TASK_ID:
            taskToWaitFor = _taskmanager->getTaskFor(semaphoreTaskId);
            break;
        default:
            break;
    }
    taskToWaitFor->semaphore->wait(_taskmanager->getTaskFor(taskId));
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
            switchTask = true;
    		break;
        case NOTIFY:
            notify(params[2], params[3]);
            break;
        case WAIT:
            wait(_taskmanager->getActiveTask()->id, params[2], params[3]);
            switchTask = true;
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
            if (params[2] == 0) {
                // Start Test-Task to toggle LED's
                Task* task = _taskmanager->create("test", false);
                TestBytes tb;
                _kernel->getLoader()->loadTaskCode(task, tb.getCodeBytes());
            } else if (params[2] == 1) {
                // Start Test-Task to toggle LED1
                Task* taskLed1 = _taskmanager->create("testLed1", false);
                TestLed1Bytes tbLed1;
                _kernel->getLoader()->loadTaskCode(taskLed1, tbLed1.getCodeBytes());
            }
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
