
#include "UserModeTask.h"

UserModeTask::UserModeTask()  {}

UserModeTask::~UserModeTask()  {}

void UserModeTask::run()  {
	MessageQueue* queue = getQueue();
	while(1)  {
		Message* message = queue->getMessage();
		// TODO: use this -> Message* message = queue->popMessage();
		executeMessage(message);
		delete message;
	}
}

void UserModeTask::writeResponse(int* response)  {
	//TODO: generate a syscall
}