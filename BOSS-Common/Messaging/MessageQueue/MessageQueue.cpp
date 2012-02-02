#include "API/Semaphore.h"
#include "MessageQueue.h"

MessageQueue::MessageQueue() {
	_capacity = MAX_MESSAGES;
	_first = 0;
	_last = 0; 
	_queue[_first] = NULL;
}

bool MessageQueue::pushMessage(Message* message) {
	// Throw exception if full
	if (isFull()) {
		// TODO: Throw Exception
		return false;
	}
	// Add message to position _last
	_queue[_last] = message;
	
	// Set index _first for next free position to push in queue
	if (_last+1 < _capacity) {
		_last++;
	} else {
		_last = 0;
	}
	return true;
}

Message* MessageQueue::popMessage(void) {
	// Suspend, if Empty
    enterSemaphore(SELF, 0);
	while (isEmpty()) {
        int params[] = {SELF, 0};
        performSystemCall(WAIT, 2, params);
	}
	
	// Get Message* at position _first
	Message* message = _queue[_first];
	
	// Remove message from the queue
	_queue[_first] = NULL;
	
	// Set index _first for next element to pop in queue
	if (_first+1 < _capacity) {
		_first++;
	} else {
		_first = 0;
	}
    exitSemaphore(SELF, 0);
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
	if (_first == _last && _queue[_first] != NULL) {
		return true;
	}	
	return false;
}
