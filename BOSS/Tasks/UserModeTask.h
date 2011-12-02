
#ifndef USERMODETASK_H_
#define USERMODETASK_H_

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

class UserModeTask {

protected:
	void writeResponse(int* response);

public:

	UserModeTask();
	virtual ~UserModeTask();

	virtual void executeMessage(Message* message) = 0;

	void run();

	//TODO: will chance after MMU exists
	virtual MessageQueue* getQueue() = 0;
};

#endif /* USERMODETASK_H_ */
