#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <queue>

#include "API/dataTypes.h"
#include "Messaging/Message/Message.h"
#include "BOSSAPI/systemCalls.h"

class MessageQueue {

private:
	std::queue<Message*> _messages;
	address _startAdress;
	address _endAdress;
	int _queueSize;
	
	Message* _first;
	Message* _last;

public:
	MessageQueue();
	MessageQueue(address startAdress, int queueSize);
	virtual ~MessageQueue();

	void addMessage(Message* message);
	Message* getMessage();
	
	void pushMessage(Message* message);
	Message* popMessage(void);
	bool isEmpty(void);
	bool isFull(void);
};

#endif /* MESSAGEQUEUE_H_ */
