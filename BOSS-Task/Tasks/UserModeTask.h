
#ifndef USERMODETASK_H_
#define USERMODETASK_H_

#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

class UserModeTask {

private:
	MemoryManager* _memoryManager;
	MessageQueue* _messagesQueue;

protected:
	void writeResponse(int* response);

public:

	UserModeTask();
	virtual ~UserModeTask();

	virtual void executeMessage(Message* message) = 0;

	void run();
};

#endif /* USERMODETASK_H_ */
