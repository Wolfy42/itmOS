
#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string.h>

class Message {

	int _taskId;
	int _paramsLength;
	int* _params;

public:

	Message(int taskId, int paramsLength, int* params);
	virtual ~Message();

	int getTaskId();
	int getParamsLength();
	int* getParams();
};

#endif /* MESSAGE_H_ */
