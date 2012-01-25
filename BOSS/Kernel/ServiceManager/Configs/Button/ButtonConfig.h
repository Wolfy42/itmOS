#ifndef BUTTONCONFIG_H_
#define BUTTONCONFIG_H_

#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#define BUTTON_CONTROL_GPIO_BASE (address) 0x48002000
#define BUTTON_GPIO_BASE         (address) 0x48310000

class ButtonConfig : public ServiceConfig  {
	public:
		ButtonConfig();
		virtual ~ButtonConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*BUTTONCONFIG_H_*/
