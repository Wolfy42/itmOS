
#include "swiHandler.h"

static SWIExecutor* _swiExecutor;

void swi_setSWIExecutor(SWIExecutor* swiExecutor)  {
	_swiExecutor = swiExecutor;
}

#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI(int swiNumber, int* parameters)  {

    _disable_interrupts( ) ;

	// Store User registers
    //TODO: test if neccassary
	//asm("	SUB 	R14, R14, #4");
	//asm("	STMFD 	R13!, {R0-R3, R12, R14}");

    _swiExecutor->executeSWI(swiNumber, parameters);

    // Restore User registers
    //asm ("	LDMFD 	R13!, {R0-R12, PC}^");

    _enable_interrupts( ) ;
}
