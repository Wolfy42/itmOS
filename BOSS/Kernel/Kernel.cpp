#include "Kernel.h"

Kernel::Kernel() {
    _mmu = new MMU(this);
    _ramManager = new RAMManager();
    _loader = new Loader(_ramManager);
    _mmu = new MMU(this);
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
	//TODO: use memory manager
//	Message* message = new Message(parameters);
//	MessageQueue* messageQueue = _messageQueues.find(message->getTaskId())->second;
//	messageQueue->addMessage(message);
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
