
#include "Message.h"

Message::Message(int taskId, int paramsLength, int* params)  {

	_taskId = taskId;
	_paramsLength = paramsLength;
	_params = params;
}

int Message::getTaskId()  {
	return _taskId;
}

int Message::getParamsLength()  {
	return _paramsLength;
}

int* Message::getParams()  {
	return _params;
}
