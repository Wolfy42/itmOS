
#include "MessageQueue.h"

MessageQueue::MessageQueue() {}

MessageQueue::~MessageQueue() {}

void MessageQueue::addMessage(Message* message)  {
	_messages.push(message);
}

Message* MessageQueue::getMessage()  {

	if (_messages.empty())  {
		performSyscall(SUSPEND, NULL);
	}

	while(_messages.empty())  {
		// The Kernel can insert messages into the queue
	}

	Message* message = _messages.back();
	_messages.pop();
	return message;
}
