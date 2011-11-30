
#include "Message.h"

Message::Message(int* swiParameter)  {

	_taskId = swiParameter[0];
	_paramsLength = swiParameter[1];

	// copy service-parameters into _params
	_params = new int[_paramsLength];
	memcpy(_params, &swiParameter[2], _paramsLength * sizeof(int));
}

Message::~Message()  {
	delete _params;
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

