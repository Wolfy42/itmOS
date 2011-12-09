
#include "MessageQueue.h"

//	TODO: remove this
MessageQueue::MessageQueue() {}

MessageQueue::MessageQueue(address startAdress) : _startAddress(startAdress) {
	_capacity = MAX_MESSAGES;
	_first = 0;
	_last = 0; 
}

MessageQueue::~MessageQueue() {}

//	TODO: remove this
void MessageQueue::addMessage(Message* message)  {
	_messages.push(message);
}

//	TODO: remove this
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

void MessageQueue::pushMessage(Message* message) {
	// Throw exception if full
	if (isFull()) {
		// TODO: Throw Exception
		return;
	}
	
	// Add message to position _last
	_queue[_last] = message;
	
	// Set index _first for next free position to push in queue
	if (_last < _capacity) {
		_last++;
	} else {
		_last = 0;
	}
}

Message* MessageQueue::popMessage(void) {
	// Suspend, if Empty
	if (isEmpty()) {
		performSyscall(SUSPEND, NULL);
	}
	
	while(isEmpty())  {
		// The kernel can insert messages into the queue
	}
	
	// Get Message* at position _first
	Message* message = _queue[_first];
	
	// Remove message from the queue
	_queue[_first] = NULL;
	
	// Set index _first for next element to pop in queue
	if (_first < _capacity) {
		_first++;
	} else {
		_first = 0;
	}
	
	return message;
}

bool MessageQueue::isEmpty(void) {
	// _first and _last index must be equal and this value must be null -> EMPTY
	if (_first == _last && _queue[_first] == NULL) {
		return true;
	}	
	return false;
}

bool MessageQueue::isFull(void) {
	// _first and _last index must be equal and this value must not be null -> FULL
	if (_first == _last && _first != NULL) {
		return true;
	}	
	return false;
}
