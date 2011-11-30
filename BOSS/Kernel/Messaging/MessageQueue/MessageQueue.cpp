
#include "MessageQueue.h"

MessageQueue::MessageQueue() {}

MessageQueue::~MessageQueue() {}

void MessageQueue::addMessage(Message* message)  {
	_messages.push(message);
}

Message* MessageQueue::getMessage()  {
	_messages.back();
	_messages.pop();
}
