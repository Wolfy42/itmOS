
#include "MessageQueue.h"

MessageQueue::MessageQueue() {}

MessageQueue::MessageQueue(address startAdress, int queueSize) : _startAdress(startAdress), _queueSize(queueSize) {
	_endAdress = (address)((int)_startAdress + _queueSize);
	
	// _first = _startAdress;
	// _last = _first; 
}

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

void pushMessage(Message* message) {
	// if isFull -> throw exception
	
	// add message to _last
	
	// _last++
}

Message* popMessage(void) {
	
	// if isEmpty -> return null
	
	// Message* message = _first
	
	// _first++
	
	// if isEmtpy -> SUSPEND?
	
	return NULL;
}

bool isEmpty(void) {
	
	// _first == _last && _first == null
	
	return false;
}

bool isFull(void) {
	
	// _first == _last && _first != null
	
	return false;
}
