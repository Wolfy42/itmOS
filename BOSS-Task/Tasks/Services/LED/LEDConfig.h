#ifndef LEDCONFIG_H_
#define LEDCONFIG_H_

#include <list>
#include "HAL/gpio.h"
#include "Tasks/Services/ServiceConfig.h"

class LEDConfig : public ServiceConfig 
{		
	public:
		LEDConfig();
		virtual ~LEDConfig();
		
		virtual char* getServiceName(void);
		virtual int getInitAddress(void);
		virtual void initRegistersForMmuMapping(void);
};

#endif /*LEDCONFIG_H_*/
