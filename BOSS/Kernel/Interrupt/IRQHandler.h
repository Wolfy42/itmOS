
#ifndef IRQHANDLER_H_
#define IRQHANDLER_H_

#include "API/dataTypes.h"
#include "Config.h"

class IRQHandler {
public:
	IRQHandler();
	virtual ~IRQHandler();

	void registerHandler(int irqNr, address handler);
	void callHandlerFor(int irqNr);

private:
	// list of all possible irq-handlers
	address _irqHandlers[MAX_IRQ_HANDLERS];

};

IRQHandler* globalIRQHandler;

#endif /* IRQHANDLER_H_ */