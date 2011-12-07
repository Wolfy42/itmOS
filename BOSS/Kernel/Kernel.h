#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Kernel/ServiceManager/ServiceManager.h" 
#include "Messaging/Message/Message.h"
#include "Messaging/MessageQueue/MessageQueue.h"

class Kernel {
	private:
		std::map<int, MessageQueue*> _messageQueues;
		ServiceManager* _serviceManager;
		void registerService(int serviceId);
	
	public:
		Kernel();
		virtual ~Kernel();
	
		void startService(int serviceId);
		void write(int* parameters);
};

#endif /* KERNEL_H_ */
