#ifndef SERIALCONFIG_H_
#define SERIALCONFIG_H_

#include <list>
#include "HAL/UART/UART_HAL.h"
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

class SerialConfig : public ServiceConfig 
{		
	public:
		SerialConfig();
		virtual ~SerialConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*SERIALCONFIG_H_*/
