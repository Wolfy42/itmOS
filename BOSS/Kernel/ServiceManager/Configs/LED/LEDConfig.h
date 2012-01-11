#ifndef LEDCONFIG_H_
#define LEDCONFIG_H_

#include <list>
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#define CONTROL_GPIO_BASE (address) 0x48002000
#define GPIO_BASE         (address) 0x49056000

class LEDConfig : public ServiceConfig 
{		
	public:
		LEDConfig();
		virtual ~LEDConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*LEDCONFIG_H_*/
