#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Kernel/Task/TaskManager.h"
#include "Kernel/ServiceManager/ServiceManager.h" 

#include "Messaging/Message/Message.h"
#include "Messaging/MessageQueue/MessageQueue.h"

class Kernel {
	private:
		TaskManager* _taskManager;
		ServiceManager* _serviceManager;
	
		std::map<int, MessageQueue*> _messageQueues;
		void registerService(int serviceId);
	
	public:
		Kernel();
		virtual ~Kernel();
	
		void startService(int serviceId);
		void write(int* parameters);
		
		TaskManager* getTaskManager(void);
};

#endif /* KERNEL_H_ */
