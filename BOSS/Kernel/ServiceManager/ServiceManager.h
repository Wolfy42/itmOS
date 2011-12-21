#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"
#include "Kernel/Task/Task.h"
#include "Kernel/Task/TaskManager.h"

class ServiceManager
{	
	private:
		TaskManager* _taskManager;
		std::map<int, Task*> _serviceTaskMapping;
	
	public:
		ServiceManager(TaskManager* taskManager);
		virtual ~ServiceManager();
		
		void startServices();
		void startService(int serviceId);
		void stopService(int serviceId);
		void restartService(int serviceId);

		Task* getTaskForService(int serviceId);
};

#endif /*SERVICEMANAGER_H_*/
