#ifndef DISPLAYSERVICE_H_
#define DISPLAYSERVICE_H_

#include "Tasks/Services/Service.h"
#include "HAL/Display/HalDisplayDriver.h"
#include "Service-API/Display/Display.h"

class DisplayService : public Service {
	private:	
		HalDisplayDriver _driver;
        int _currentTaskId;
		virtual void executeMessage(Message* message);
	
        bool checkScreenRights(int taskId);
        void changeTo(int taskId);
	public:
		DisplayService();
		virtual ~DisplayService();
        
};

#endif /*DISPLAYSERVICE_H_*/
