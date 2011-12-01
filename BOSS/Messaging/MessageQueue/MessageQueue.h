
#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_

#include <queue>

#include "Messaging/Message/Message.h"

class MessageQueue {

private:
	std::queue<Message*> _messages;

public:
	MessageQueue();
	virtual ~MessageQueue();

	void addMessage(Message* message);
	Message* getMessage();
};

#endif /* MESSAGEQUEUE_H_ */
