
#include "UserModeTask.h"

extern volatile unsigned int messagesStart;

UserModeTask::UserModeTask()  {
	_memoryManager = (MemoryManager*)&messagesStart;
	_messagesQueue = _memoryManager->getMessageQueue();
}

UserModeTask::~UserModeTask()  {}

void UserModeTask::run()  {
	while(1)  {
		Message* message = _messagesQueue->popMessage();
		executeMessage(message);

		_memoryManager->remove(message, true);
	}
}

void UserModeTask::writeResponse(int* response)  {
	//TODO: generate a syscall
}
