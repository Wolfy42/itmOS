#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"
#include "BOSSAPI/serviceCalls.h"

class ServiceManager
{	
	public:
		ServiceManager();
		virtual ~ServiceManager();
		
		void startService(int service); 
};

#endif /*SERVICEMANAGER_H_*/
