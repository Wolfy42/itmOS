#include "Kernel.h"

Kernel::Kernel() {
    _ramManager = new RAMManager();
    _mmu = new MMU(this);
    _loader = new Loader(_ramManager);
	_taskManager = new TaskManager(_mmu);
	_serviceManager = new ServiceManager(_taskManager, _loader);
	_handlerManager = new HandlerManager(this);
	_executor = new SystemCallExec(this, _taskManager);
    
	initInterruptHandler(
			_handlerManager->getIrqHandler(), 
			_handlerManager->getSwiHandler(), 
			_taskManager, _mmu);
}

Kernel::~Kernel() {
	delete _taskManager;
	delete _serviceManager;
}

void Kernel::write(int* parameters)  {
	int serviceId = parameters[0];
	int length = parameters[1];
	int* params = &parameters[2];

	int activeTaskId = _taskManager->getActiveTask()->id;
	Task* task = _serviceManager->getTaskForService(serviceId);

	MemoryManager* memoryManager = task->memoryManager;
	MessageQueue* messageQueue = memoryManager->getMessageQueue();

	Message* message = memoryManager->createMessage(activeTaskId, length, params);
	messageQueue->pushMessage(message);
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
