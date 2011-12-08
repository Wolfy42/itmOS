#include "Kernel.h"

Kernel::Kernel() {
	_taskManager = new TaskManager();
	_serviceManager = new ServiceManager(this, _taskManager);
	_handlerManager = new HandlerManager(this);
	_executor = new SystemCallExec(this, _taskManager);
    _mmu = new MMU();
	initInterruptHandler(
			_handlerManager->getIrqHandler(), 
			_handlerManager->getSwiHandler(), 
			_taskManager, _mmu);
}

Kernel::~Kernel() {
	delete _taskManager;
	delete _serviceManager;
}

void Kernel::startService(int serviceId) {
	// Register the service first
	_serviceManager->registerService(serviceId);
	
	// Start the Service
	_serviceManager->startService(serviceId);
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

std::map<int, MessageQueue*> Kernel::getMessageQueues() {
	return _messageQueues;
}
