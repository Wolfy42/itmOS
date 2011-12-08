#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_

#include <map>

#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"
#include "BOSSAPI/serviceCalls.h"

// Forward-declaration
class Kernel;

class ServiceManager
{	
	private:
		Kernel* _kernel;
	
	public:
		ServiceManager(Kernel* kernel);
		virtual ~ServiceManager();
		
		void startService(int service); 
};

#endif /*SERVICEMANAGER_H_*/
