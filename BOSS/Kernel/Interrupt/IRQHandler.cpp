
#include "IRQHandler.h"

IRQHandler* globalIRQHandler;

#pragma INTERRUPT (IRQ) ;
extern "C"  void c_intIRQ()  {

	// Determine Nr. of IRQ (e.g. GPTIMER2 is IRQ_38 --> irqNr = 38)
	int irqNr = *(INTCPS_SIR_IRQ);

	// Call Global IRQ-Handler
	globalIRQHandler->callHandlerFor(irqNr);

	// Reset IRQ output and enable new IRQ generation.
	*(INTCPS_CONTROL) |= 0x1;
}

IRQHandler::IRQHandler() {
	globalIRQHandler = this;
}

IRQHandler::~IRQHandler() {}

void IRQHandler::registerHandler(int irqNr, void (*handler)(void))  {
	_irqHandlers[irqNr] = handler;

	int registerNr = irqNr / 32;
	int irqBit = irqNr % 32;

	switch (registerNr)  {
		case 0:
			*INTCPS_MIR_SET_0 |= (1 << irqBit);
			break;
		case 1:
			*INTCPS_MIR_SET_1 |= (1 << irqBit);
			break;
		case 2:
			*INTCPS_MIR_SET_2 |= (1 << irqBit);
			break;
	}
}

void IRQHandler::callHandlerFor(int irqNr)  {
	(*_irqHandlers[irqNr])();
}
