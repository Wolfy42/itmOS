#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <string.h>

#include "API/dataTypes.h"
#include "API/systemCalls.h"
#include "Messaging/Message/Message.h"

#define MAX_MESSAGES 42

class MessageQueue {

private:
	
	Message* _queue[MAX_MESSAGES];
	int _capacity;
	int _first;
	int _last;

public:
	MessageQueue();

	void pushMessage(Message* message);
	Message* popMessage(void);

	bool isEmpty(void);
	bool isFull(void);
};

#endif /* MESSAGEQUEUE_H_ */
