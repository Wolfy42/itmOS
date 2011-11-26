#include "IRQHandler.h"

IRQHandler* globalIRQHandler;

asm("	.bss _tcb1, 4 ");
asm("	.bss _tcb2, 4 ");

asm("	.global _tcb1 ");
asm("	.global _tcb2 ");

asm("tcb1 .field _tcb1, 32 ");
asm("tcb2 .field _tcb2, 32 ");

extern int tcb1;
extern int tcb2;

#pragma TASK
extern "C" void c_intIRQ()  {
	
	// Store User registers
	asm("	SUB R14, R14, #4");
	asm("	STMFD R13!, {R0-R3, R12, R14}");

	// Determine Nr. of IRQ (e.g. GPTIMER2 is IRQ_38 --> irqNr = 38)
	int irqNr = *(INTCPS_SIR_IRQ);

	// Call Global IRQ-Handler
	globalIRQHandler->callHandlerFor(irqNr);

	// Reset IRQ output and enable new IRQ generation.
	*(INTCPS_CONTROL) |= 0x1;

	// Get the TCB's of the processes to switch the context
	tcb1 = (int)&_tasks[activeTask]->tcb.CPSR;
	scheduleNextTask();
	tcb2 = (int)&_tasks[activeTask]->tcb.CPSR;

	// Load addresses of the TCB's of the Tasks to switch into R0 and R1

	asm("	LDR 	R0, tcb1 ;" );
	asm("	LDR 	R0, [R0], #0 ;" );
	asm("	LDR 	R1, tcb2 ;" );
	asm("	LDR 	R1, [R1], #0 ;" );

	// First store the old precess's User mode state to the PCB pointed to by R0."

	asm("	MRS 	R12, SPSR					; Get CPSR of interrupted process" );
	asm("	STR 	R12, [R0], #8				; Store CPSR to PCB, point R0 at PCB location for R0 value" );
	asm("	LDMFD	R13!, {R2, R3}				; Reload R0/R1 of interrupted process from stack" );
	asm("	STMIA 	R0!, {R2, R3}				; Store R0/R1 values to PCB, point R0 at PCB location for R2 value" );
	asm("	LDMFD 	R13!, {R2, R3, R12, R14}  	; Reload remaining stacked values" );
	asm("	STR 	R14, [R0, #-12]				; Store R14_irq, the interrupted process's restart address" );
	asm("	STMIA 	R0, {R2-R14}^				; Store user R2-R14 ");

	// Then load the new process's User mode state and return to it.");

	asm("	LDMIA 	R1!, {R12, R14}  			; Put interrupted process's CPSR" );
	asm("	MSR 	SPSR_fsxc, R12				; and restart address in SPSR_irq and R14_irq" );
	asm("	LDMIA 	R1, {R0-R14}^				; Load user R0-R14" );
	asm("	NOP									; Note: cannot use banked register immediately after User mode LDM" );
	asm("	MOVS 	PC, R14						; Return to address in R14_irq, with SPSR_irq -> CPSR transfer" );

}

IRQHandler::IRQHandler() {
	globalIRQHandler = this;
	
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
	if (irqNr > GPT_MPU_IRQ_ID_START && irqNr < GPT_MPU_IRQ_ID_END) {
		callHandlerForTimerInterrupt(irqNr);
	} else {	
		callHandlerIfAvailable(irqNr);
	}
}

void IRQHandler::callHandlerForTimerInterrupt(int irqNr) {
	// Clear pending interrupts	
	Timer timer = HalTimerDriver::timerForIRQNumber(irqNr);
	HalTimerDriver::clearPendingInterrupts(timer);
		
		
	callHandlerIfAvailable(irqNr);	

	
	//HalTimerDriver::resetInternalCounter(GPTIMER2);
	// Set counter to 0 if MATCH MODE
}

void IRQHandler::callHandlerIfAvailable(int irqNr) {
	if (_irqHandlers[irqNr] != NULL) {
		(*_irqHandlers[irqNr])();
	}
}

void contextSwitch() {
	
}
