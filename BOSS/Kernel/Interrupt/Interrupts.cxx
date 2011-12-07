#include "Interrupts.h"

/*
 * 	Defines for SoftwareInterrupt
 */
#define SAVED_REGISTERS_SPACE (14 * 4)
#define WEIRD_EXTRA_SPACE (1 * 4)
#define SWI_PARAMETERS_SPACE (2 * 4)


/*
 * 	static Handlers for the Interrupts
 */
static IRQHandler* _IRQHandler;
static SWIHandler* _SWIHandler;
static TaskManager* _TaskManager;

/*
 *	Global Variables for Context Switch
 */
asm("	.bss _tcb1, 4 ");
asm("	.bss _tcb2, 4 ");
asm("	.bss _stack_pointer_saved_context, 4 ");
asm("	.bss _stack_pointer_original, 4 ");

asm("	.global _tcb1 ");
asm("	.global _tcb2 ");
asm("	.global _stack_pointer_saved_context ");
asm("	.global _stack_pointer_original ");

asm("tcb1 .field _tcb1, 32 ");
asm("tcb2 .field _tcb2, 32 ");
asm("stack_pointer_saved_context .field _stack_pointer_saved_context, 32 ");
asm("stack_pointer_original .field _stack_pointer_original, 32 ");

extern int tcb1;
extern int tcb2;
extern int stack_pointer_saved_context;
extern int stack_pointer_original;


/*
 *	Init function for the Interrupt handlers
 */
void initInterruptHandler(IRQHandler* irq, SWIHandler* swi, TaskManager* tm) {

	_IRQHandler = irq;
	_SWIHandler = swi;
	_TaskManager = tm;
}


/*
 *  Save StackPointer and Return address Define
 * 	- use this before contextSwitch
 */
#define SAVECONTEXT_IRQ \
	asm("	SUB 	R14, R14, #4				; Put return address of the interrupted task into R14 "); \
	asm("   STMFD 	R13!, {R0-R12, R14}		; Save Task-Registers "); \
	asm(" LDR     R0, stack_pointer_saved_context"); \
	asm(" STR     R13, [R0], #0"); \
	//stack_pointer_original = stack_pointer_saved_context + SAVED_REGISTERS_SPACE;
	
#define SAVECONTEXT_SWI \
	asm(" STMFD   R13!, {R0-R12, R14} ; Save Process-Registers "); \
	asm(" LDR     R0, stack_pointer_saved_context"); \
	asm(" STR     R13, [R0], #0"); \
	stack_pointer_original = stack_pointer_saved_context + SAVED_REGISTERS_SPACE + SWI_PARAMETERS_SPACE + WEIRD_EXTRA_SPACE;

/*
 * 	Context Switch Routine
 * 	- MUST: save stackpointer and return address before you execute this routine
 */
void contextSwitch() {
	
	// reload the stack pointer of the interrupt handler to get
	// the saved context
	asm(" LDR     R13, stack_pointer_saved_context");
	asm(" LDR     R13, [R13], #0");
	
	
	// Get the TCB's of the processes to switch the context
	if (_TaskManager->getActiveTask() != NULL) {
		tcb1 = (int)&_TaskManager->getActiveTask()->tcb.CPSR;
	} else {
		tcb1 = NULL;
	}
	_TaskManager->schedule();
	tcb2 = (int)&_TaskManager->getActiveTask()->tcb.CPSR;


	// Load addresses of the TCB's of the Tasks to switch into R0 and R1

	asm("	LDR 	R0, tcb1 ;" );
	asm("	LDR 	R0, [R0], #0 ;" );
	asm("	LDR 	R1, tcb2 ;" );
	asm("	LDR 	R1, [R1], #0 ;" );

	// First store the old precess's User mode state to the PCB pointed to by R0."
	if (tcb1 != NULL) {
		asm("	MRS 	R12, SPSR					; Get CPSR of interrupted process" );
		asm("	STR 	R12, [R0], #8				; Store CPSR to PCB, point R0 at PCB location for R0 value" );
		asm("	LDMFD	R13!, {R2, R3}				; Reload R0/R1 of interrupted process from stack" );
		asm("	STMIA 	R0!, {R2, R3}				; Store R0/R1 values to PCB, point R0 at PCB location for R2 value" );
		asm("   LDMFD   R13!, {R2-R12, R14}	; Reload remaining stacked values" );
		asm("	STR 	R14, [R0, #-12]				; Store R14_irq, the interrupted process's restart address" );
		asm("	STMIA 	R0, {R2-R14}^				; Store user R2-R14 ");
	}
	// Then load the new process's User mode state and return to it.");

	asm("	LDMIA 	R1!, {R12, R14}  			; Put interrupted process's CPSR" );
	asm("	MSR 	SPSR_fsxc, R12				; and restart address in SPSR_irq and R14_irq" );
	asm("	LDMIA 	R1, {R0-R14}^				; Load user R0-R14" );
	asm("	NOP									; Note: cannot use banked register immediately after User mode LDM" );

	// !! The next line is a added to the code in the ARM-book, because
	//    normally this would be called at the end of the function, but we don't reach that
	//asm("	ADD     R13, R13, #4 ");

	asm("	MOVS 	PC, R14						; Return to address in R14_irq, with SPSR_irq -> CPSR transfer" );
}




/* 
 *	IRQ Routine 
 */
#pragma TASK
extern "C" void c_intIRQ()  {
	
	// This will be called before enterint the function
	// SUB             R14, R14, #4
	SAVECONTEXT_IRQ


	// Determine Nr. of IRQ (e.g. GPTIMER2 is IRQ_38 --> irqNr = 38)
	//int irqNr = *(INTCPS_SIR_IRQ);

	// Call Global IRQ-Handler
	_IRQHandler->callHandlerFor(*(INTCPS_SIR_IRQ));

	// Reset IRQ output and enable new IRQ generation.
	*(INTCPS_CONTROL) |= 0x1;

	contextSwitch();
}




/*
 * 	Software Interrupt
 * 	- Software Interrupt Handler functions should return true
 * 		if a context switch is needed
 */
#pragma TASK
extern "C" void c_intSWI(int swiNumber, int* parameters)  {

	// save context
	SAVECONTEXT_SWI

	// if cs is true a context switch is gonna happen
    bool cs = _SWIHandler->handle(swiNumber, parameters);
    
    if (cs == true) {
    	
    	// perform a context switch
    	contextSwitch();
    } 
    
	// restore stackpointer of swi
	asm(" LDMFD   R13!, {R0-R12, PC}^");
}