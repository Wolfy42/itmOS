
#include "UserModeTask.h"

UserModeTask::UserModeTask()  {}

UserModeTask::~UserModeTask()  {}

void UserModeTask::run()  {
	MessageQueue* queue = getQueue();
	while(1)  {
		Message* message = queue->getMessage();
		executeMessage(message);
		delete message;
	}
}

void UserModeTask::writeResponse(int* response)  {
	//TODO: generate a syscall
}
