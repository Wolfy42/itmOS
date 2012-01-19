
#ifndef USERMODETASK_H_
#define USERMODETASK_H_

#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

class UserModeTask {

private:
	MemoryManager* _memoryManager;
	MessageQueue* _messagesQueue;

public:

	UserModeTask();
	virtual ~UserModeTask();

	virtual void executeMessage(Message* message) = 0;

	void run();
	void writeResponse(int callerId, int lenght, int params[]);
};

#endif /* USERMODETASK_H_ */
