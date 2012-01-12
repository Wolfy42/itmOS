#ifndef DISPLAYSERVICE_H_
#define DISPLAYSERVICE_H_

#include "Tasks/Services/Service.h"
#include "Tasks/Services/Display/Graphics.h"

class DisplayService : public Service {
	private:	
		virtual void executeMessage(Message* message);
	
	public:
		DisplayService();
		virtual ~DisplayService();
};

#endif /*DISPLAYSERVICE_H_*/
