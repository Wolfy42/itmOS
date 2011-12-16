#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"
#include "Kernel/Task/TaskManager.h"

// Forward-declaration
class Kernel;

class ServiceManager
{	
	private:
		Kernel* _kernel;
		TaskManager* _taskManager;
		std::map<int, int> _taskIdMapping;
	
	public:
		ServiceManager(Kernel* kernel, TaskManager* taskManager);
		virtual ~ServiceManager();
		
		void registerService(int service);
		void startService(int service); 
		void stopService(int service);
		void restartService(int service);
		
		TID_t getTaskIdForService(int service);
};

#endif /*SERVICEMANAGER_H_*/
