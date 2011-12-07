
#ifndef IRQHANDLER_H_
#define IRQHANDLER_H_

#include "HAL/IRQConfig.h"

class IRQHandler {
public:
	IRQHandler();
	virtual ~IRQHandler();

	void registerHandler(int irqNr, void (*handler)(void));
	void callHandlerFor(int irqNr);

private:

	// list of all possible irq-handlers
	void (*_irqHandlers[MAX_IRQ_HANDLERS])(void);
	
	void callHandlerForTimerInterrupt(int irqNr);
	void callHandlerIfAvailable(int irqNr);
	
};

#endif /* IRQHANDLER_H_ */
