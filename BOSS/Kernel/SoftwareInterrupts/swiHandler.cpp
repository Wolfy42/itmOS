#include "Kernel/SoftwareInterrupts/swiHandler.h"

//TODO: this code should not be here
/*void endTask(TID_t id) {
	
	deleteTask(id);
	//yield();
	activeTask = -1;
	_enable_interrupts();
	while (1) {
		
	}
}*/

static Kernel* _kernel;

void swi_setKernel(Kernel* kernel)  {
	_kernel = kernel;
}

// TODO: STOP PLENKING!!!
#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI(int swiNumber, int* parameters)  {
	
	// TODO: STOP PLENKING!!!
    _disable_interrupts( ) ;

	// Store User registers
	asm("	SUB 	R14, R14, #4");
	asm("	STMFD 	R13!, {R0-R3, R12, R14}");

    switch (swiNumber) {
         case EXIT:
        	//endTask(parameters[0]);
            break;
        case KILL:
            break;
        case EXEC:
            break;
        case FORK:
            break;
        case YIELD:
            break;
        case SERVICE_CALL:
        	_kernel->callService(parameters);
            break;
        case SERVICE_RESPONSE:
            break;
        default:
            break;
    }
    // Restore User registers
    asm ("	LDMFD 	R13!, {R0-R12, PC}^");

    // TODO: STOP PLENKING!!!
    _enable_interrupts( ) ;
}
