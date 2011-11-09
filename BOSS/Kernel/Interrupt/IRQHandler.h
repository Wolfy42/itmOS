
#ifndef IRQHANDLER_H_
#define IRQHANDLER_H_

#include "API/dataTypes.h"
#include "Config.h"
#include "HAL/Timer/TimerClass.h"


class IRQHandler {
public:
	IRQHandler();
	virtual ~IRQHandler();

	void registerHandler(int irqNr, void (*handler)(void));
	void callHandlerFor(int irqNr);

private:
	// list of all possible irq-handlers
	void (*_irqHandlers[MAX_IRQ_HANDLERS])(void);

};

#endif /* IRQHANDLER_H_ */
