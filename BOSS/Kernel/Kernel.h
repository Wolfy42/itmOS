
#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Messaging/Message/Message.h"
#include "Messaging/MessageQueue/MessageQueue.h"

class Kernel {
private:

	std::map<int, MessageQueue*> _messageQueues;

public:
	Kernel();
	virtual ~Kernel();

	void write(int* parameters);

};

#endif /* KERNEL_H_ */
