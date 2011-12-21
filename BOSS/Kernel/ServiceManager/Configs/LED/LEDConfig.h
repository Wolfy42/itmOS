#ifndef LEDCONFIG_H_
#define LEDCONFIG_H_

#include <list>
#include "HAL/gpio.h"
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

class LEDConfig : public ServiceConfig 
{		
	public:
		LEDConfig();
		virtual ~LEDConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*LEDCONFIG_H_*/
