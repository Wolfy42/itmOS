
#include "MessageQueue.h"

MessageQueue::MessageQueue() {}

MessageQueue::~MessageQueue() {}

void MessageQueue::addMessage(Message* message)  {
	_messages.push(message);
}

Message* MessageQueue::getMessage()  {

	//TODO: needs a semaphore, so that the task will wait here

	_messages.back();
	_messages.pop();
}
