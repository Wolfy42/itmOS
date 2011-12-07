#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Kernel/Task/TaskManager.h"
#include "Kernel/ServiceManager/ServiceManager.h" 
#include "Kernel/Interrupt/HandlerManager.h"
#include "Kernel/SystemCalls/SystemCallExec.h"
#include "Kernel/Interrupt/Interrupts.h"

#include "Messaging/Message/Message.h"
#include "Messaging/MessageQueue/MessageQueue.h"

// Forward-declaration
class HandlerManager;
class SystemCallExec;

class Kernel {
	private:
		TaskManager* _taskManager;
		ServiceManager* _serviceManager;
		HandlerManager* _handlerManager;
		SystemCallExec* _executor;
	
		std::map<int, MessageQueue*> _messageQueues;
		void registerService(int serviceId);
	
	public:
		Kernel();
		virtual ~Kernel();
	
		void startService(int serviceId);
		void write(int* parameters);
		
		TaskManager* getTaskManager(void);
		ServiceManager* getServiceManager(void);
		HandlerManager* getHandlerManager(void);
		SystemCallExec* getExecutor(void);
};

#endif /* KERNEL_H_ */
