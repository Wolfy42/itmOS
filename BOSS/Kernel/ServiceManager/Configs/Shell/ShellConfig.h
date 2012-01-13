#ifndef SHELLCONFIG_H_
#define SHELLCONFIG_H_

#include <list>
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"


class ShellConfig : public ServiceConfig 
{		
	public:
		ShellConfig();
		virtual ~ShellConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*SHELLCONFIG_H_*/
