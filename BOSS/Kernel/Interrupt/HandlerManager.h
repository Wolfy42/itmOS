#ifndef HANDLERMANAGER_H_
#define HANDLERMANAGER_H_

#include "Kernel/Interrupt/Handler/IRQHandler.h"
#include "Kernel/Interrupt/Handler/SWIHandler.h"

// Forward-declaration
class Kernel;
class SWIHandler;

class HandlerManager
{
	private:
		Kernel* _kernel;
		IRQHandler* _irqHandler;
		SWIHandler* _swiHandler;
	
	public:
		HandlerManager(Kernel* kernel);
		virtual ~HandlerManager();
		
		IRQHandler* getIrqHandler(void);
		SWIHandler* getSwiHandler(void);
};

#endif /*HANDLERMANAGER_H_*/
