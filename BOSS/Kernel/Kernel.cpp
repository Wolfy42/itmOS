#include "Kernel.h"
#include "Kernel/Task/Semaphore.h"
#include <string.h>

Kernel::Kernel() {
    _ramManager = new RAMManager();
    _mmu = new MMU(this);
    _loader = new Loader(_ramManager);
	_taskManager = new TaskManager(_mmu);
	_serviceManager = new ServiceManager(_taskManager, _loader);
    _executor = new SystemCallExec(this, _taskManager);
	_handlerManager = new HandlerManager(this);
    
    _displayTaskId = 0;
	initInterruptHandler(
			_handlerManager->getIrqHandler(), 
			_handlerManager->getSwiHandler(), 
			_taskManager, _mmu);
			
	initScheduler();
}

Kernel::~Kernel() {
	delete _taskManager;
	delete _serviceManager;
}

void interrupted(void) {
	// Bla
}

void Kernel::initScheduler() {
	srand_(time_());
	_handlerManager->getIrqHandler()->registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER1), interrupted);

	HalTimerDriver::init(GPTIMER1, GPT_IRQMODE_OVERFLOW, 1);
	HalTimerDriver::start(GPTIMER1);
}

void Kernel::write(int* parameters)  {
	int serviceId = parameters[0];
	int length = parameters[1];
	int* params = &parameters[2];

	Task* task = _serviceManager->getTaskForService(serviceId);
	if (task != NULL)  {
		writeIntoMessageQueue(task, length, params);
	}
}

void Kernel::writeResponse(int* parameters)  {
	int taskId = parameters[0];
	int length = parameters[1];
	int* params = &parameters[2];

	Task* task = getTaskManager()->getTaskFor(taskId);
	if (task != NULL)  {
		writeIntoMessageQueue(task, length, params);
	}
}

void Kernel::writeIntoMessageQueue(Task* task, int length, int params[])  {
	int activeTaskId = _taskManager->getActiveTask()->id;

    if ((std::strcmp(_taskManager->getActiveTask()->name, "ScreenSwitcher") == 0) && (params[0] == 398)) {
        activeTaskId = -1;
        int nextTaskId = -1;
        Task** tasks = _taskManager->getTaskList();
        
        for (int i = _displayTaskId + 1; nextTaskId < 0; i++) {
            if (i >= MAX_TASKS) {
                i = 0;
            }
            if (tasks[i] != NULL) {
                nextTaskId = i;
            }
        }
        
        _displayTaskId = nextTaskId;
        params[1] = _displayTaskId;
    }

	task->status = Ready;

	MemoryManager* memoryManager = task->memoryManager;
	MessageQueue* messageQueue = memoryManager->getMessageQueueWithoutVirtualOffset();

	if (!messageQueue->isFull())  {
		Message* message = memoryManager->createMessage(activeTaskId, length, params);
		messageQueue->pushMessage(message);
	};
}

TaskManager* Kernel::getTaskManager(void) {
	return _taskManager;
}

ServiceManager* Kernel::getServiceManager(void) {
	return _serviceManager;
}

HandlerManager* Kernel::getHandlerManager(void) {
	return _handlerManager;
}

SystemCallExec* Kernel::getExecutor(void) {
	return _executor;
}

Loader* Kernel::getLoader(void) {
	return _loader;
}

RAMManager* Kernel::getRAMManager(void) {
    return _ramManager;
}

