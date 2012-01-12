
#ifndef DISPLAYCONFIG_H_
#define DISPLAYCONFIG_H_

#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#define DISPC_BASE  (address) 0x48050000
#define CM_DSS_BASE (address) 0x48004000

class DisplayConfig: public ServiceConfig  {

	public:
		DisplayConfig();
		virtual ~DisplayConfig();

		virtual void initRegistersForMmuMapping(void);
};

#endif /* DISPLAYCONFIG_H_ */
