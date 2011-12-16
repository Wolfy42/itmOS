#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Kernel/Task/TaskManager.h"
#include "Kernel/ServiceManager/ServiceManager.h" 
#include "Kernel/Interrupt/HandlerManager.h"
#include "Kernel/SystemCalls/SystemCallExec.h"
#include "Kernel/Interrupt/Interrupts.h"
#include "Kernel/RAMManager/RAMManager.h"
#include "Kernel/MMU/mmu.h"
#include "Loader/Loader.h"

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
        MMU* _mmu;
        RAMManager* _ramManager;
        Loader* _loader;
	
		std::map<int, MessageQueue*> _messageQueues;
	
	public:
		Kernel();
		virtual ~Kernel();
	
		void startService(int serviceId);
		void write(int* parameters);
		
		// Getters
		TaskManager* getTaskManager(void);
		ServiceManager* getServiceManager(void);
		HandlerManager* getHandlerManager(void);
		SystemCallExec* getExecutor(void);
		Loader* getLoader(void);
        RAMManager* getRAMManager(void);
		std::map<int, MessageQueue*> getMessageQueues();
};

#endif /* KERNEL_H_ */
