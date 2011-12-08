#ifndef LEDCONFIG_H_
#define LEDCONFIG_H_

#include <list>
#include "HAL/gpio.h"
#include "Tasks/Services/ServiceConfig.h"

class SerialConfig : public ServiceConfig 
{		
	public:
		SerialConfig();
		virtual ~SerialConfig();
		
		virtual char* getServiceName(void);
		virtual int getInitAddress(void);
		virtual void initRegistersForMmuMapping(void);
};

#endif /*LEDCONFIG_H_*/
