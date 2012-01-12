#ifndef DISPLAYSERVICE_H_
#define DISPLAYSERVICE_H_

#include "Tasks/Services/Service.h"
#include "HAL/Display/HalDisplayDriver.h"

class DisplayService : public Service {
	private:	
		virtual void executeMessage(Message* message);
	
	public:
		DisplayService();
		virtual ~DisplayService();
};

#endif /*DISPLAYSERVICE_H_*/
