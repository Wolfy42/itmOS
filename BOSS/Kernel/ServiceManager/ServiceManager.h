#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Kernel/ServiceManager/Configs/LED/LEDConfig.h"
#include "Kernel/ServiceManager/Configs/Serial/SerialConfig.h"
#include "Kernel/ServiceManager/Configs/Display/DisplayConfig.h"

#include "Kernel/Task/Task.h"
#include "Kernel/Task/TaskManager.h"

#include "Loader/Loader.h"
#include "Loader/TasksHex.h"
#include "Loader/TasksHex/SerialBytes.h"
#include "Loader/TasksHex/LedBytes.h"
#include "Loader/TasksHex/DisplayBytes.h"

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
