#include "IRQHandler.h"

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Task/TaskManager.h"
#include "HAL/gpt.h"
#include "API/dataTypes.h"

IRQHandler::IRQHandler() {
	
	// Initialize all handlers to NULL 
	for (int i = 0; i < MAX_IRQ_HANDLERS; i++) {
		_irqHandlers[i] = NULL;
	}
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
	if (irqNr >= GPT_MPU_IRQ_ID_START && irqNr <= GPT_MPU_IRQ_ID_END) {
		callHandlerForTimerInterrupt(irqNr);
	} else {	
		callHandlerIfAvailable(irqNr);
	}
}

void IRQHandler::callHandlerForTimerInterrupt(int irqNr) {
	// Clear pending interrupts	
	Timer timer = HalTimerDriver::timerForIRQNumber(irqNr);
	HalTimerDriver::clearPendingInterrupts(timer);
		
	// Call Handler
	callHandlerIfAvailable(irqNr);	

	// Set counter to 0 if MATCH MODE
	if (HalTimerDriver::getMode(timer) == GPT_IRQMODE_MATCH) { 
		HalTimerDriver::resetInternalCounter(timer);
	}
}

void IRQHandler::callHandlerIfAvailable(int irqNr) {
	if (_irqHandlers[irqNr] != NULL) {
		(*_irqHandlers[irqNr])();
	}
}


