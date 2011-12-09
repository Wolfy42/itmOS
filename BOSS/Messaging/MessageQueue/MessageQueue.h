#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

//	TODO: remove this
#include <queue>

#include "API/dataTypes.h"
#include "Messaging/Message/Message.h"
#include "BOSSAPI/systemCalls.h"

#define MAX_MESSAGES 42

class MessageQueue {

private:
//	TODO: remove this
	std::queue<Message*> _messages;
	
	Message* _queue[MAX_MESSAGES];
	int _capacity;
	int _first;
	int _last;

public:
	MessageQueue();
	virtual ~MessageQueue();

//	TODO: remove this
	void addMessage(Message* message);
	Message* getMessage();
	
	void pushMessage(Message* message);
	Message* popMessage(void);
	bool isEmpty(void);
	bool isFull(void);
};

#endif /* MESSAGEQUEUE_H_ */
