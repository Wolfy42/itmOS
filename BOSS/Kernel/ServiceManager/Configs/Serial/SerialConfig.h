#ifndef SERIALCONFIG_H_
#define SERIALCONFIG_H_

#include <list>
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#define UART1 0x4806A000 /* UART only */
#define UART2 0x4806C000 /* UART only */
#define UART3 0x49020000 /* UART, IrDA, CIR */

class SerialConfig : public ServiceConfig 
{		
	public:
		SerialConfig();
		virtual ~SerialConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*SERIALCONFIG_H_*/
