#include "Kernel.h"

Kernel::Kernel() {
	_taskManager = new TaskManager();
	_serviceManager = new ServiceManager(this);
}

Kernel::~Kernel() {
	delete _taskManager;
	delete _serviceManager;
}

void Kernel::registerService(int serviceId)  {
	//TODO: change this!
	MessageQueue* queue = new MessageQueue();
	*(address)0x820F0000 = (unsigned int)queue;
	_messageQueues.insert(std::pair<int, MessageQueue*>(serviceId, queue));
}

void Kernel::startService(int serviceId) {
	// Register the service first
	registerService(serviceId);
	
	// Start the Service
	_serviceManager->startService(serviceId);
}

void Kernel::write(int* parameters)  {
	Message* message = new Message(parameters);
	MessageQueue* messageQueue = _messageQueues.find(message->getTaskId())->second;
	messageQueue->addMessage(message);
}

TaskManager* Kernel::getTaskManager(void) {
	return _taskManager;
}
