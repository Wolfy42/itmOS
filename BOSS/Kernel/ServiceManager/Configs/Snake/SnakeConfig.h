#ifndef SNAKECONFIG_H_
#define SNAKECONFIG_H_

#include <list>
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"


class SnakeConfig : public ServiceConfig 
{		
	public:
		SnakeConfig();
		virtual ~SnakeConfig();
		
		virtual void initRegistersForMmuMapping(void);
};

#endif /*SNAKECONFIG_H_*/
