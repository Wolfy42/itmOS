#ifndef DISPLAYSERVICE_H_
#define DISPLAYSERVICE_H_

#include "Tasks/Services/Service.h"
#include "Tasks/Services/Display/Graphics.h"
#include "HAL/Display/HalDisplayDriver.h"

#define WIDTH 1024
#define HEIGHT 768
#define RES_WIDTH 1024
#define RES_HEIGHT 768
#define FBADDR ((char *)0x83000000)

class DisplayService : public Service {
	private:	
		virtual void executeMessage(Message* message);
	
	public:
		DisplayService();
		virtual ~DisplayService();
};

#endif /*DISPLAYSERVICE_H_*/
