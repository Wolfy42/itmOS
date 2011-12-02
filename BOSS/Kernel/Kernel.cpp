
#include "Kernel.h"

Kernel::Kernel() {}
Kernel::~Kernel() {}

void Kernel::registerService(int serviceId)  {

	//TODO: change this!
	MessageQueue* queue = new MessageQueue();
	*(address)0x820F0000 = (unsigned int)queue;
	_messageQueues.insert(std::pair<int, MessageQueue*>(serviceId, queue));
}

void Kernel::write(int* parameters)  {

	Message* message = new Message(parameters);
	MessageQueue* messageQueue = _messageQueues.find(message->getTaskId())->second;
	messageQueue->addMessage(message);
}
