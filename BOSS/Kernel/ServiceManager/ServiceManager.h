#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"
#include "Kernel/Task/Task.h"
#include "Kernel/Task/TaskManager.h"
#include "Loader/Loader.h"
#include "Loader/TasksHex.h"
#include "Loader/TasksHex/LedBytes.h"

class ServiceManager
{	
	private:
		TaskManager* _taskManager;
		Loader* _loader;
		std::map<int, Task*> _serviceTaskMapping;
	
	public:
		ServiceManager(TaskManager* taskManager, Loader* loader);
		virtual ~ServiceManager();
		
		void startServices();
		void startService(char* serviceName, int serviceId, CodeBytes* codeBytes, ServiceConfig* config);
		void stopService(int serviceId);

		Task* getTaskForService(int serviceId);
};

#endif /*SERVICEMANAGER_H_*/
