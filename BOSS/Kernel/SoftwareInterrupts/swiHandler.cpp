#include "API/dataTypes.h"
#include "Lib/bitOperations.h"
#include "BOSSAPI/systemCalls.h"
#include "Service/Service.h"
#include "Kernel/MMU/mmu.h"
#include "Kernel/TaskManagement/Tasks.h"
#include "Kernel/Kernel.h"

#define INIT 0x0

void init() {
    mmu_initMemoryForTask(0);
}

void endTask(TID_t id) {
	
	deleteTask(id);
	//yield();
	activeTask = -1;
	_enable_interrupts();
	while (1) {
		
	}
}

extern Kernel* _kernel;

// TODO: STOP PLENKING!!!
#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI(int swiNumber, int* parameters)  {
	
	// TODO: STOP PLENKING!!!
    _disable_interrupts( ) ;
    static byte initialized = 0;

    switch (swiNumber) {
        case INIT:
            if (initialized == 0) {
                init();
                initialized = 1;
            }
            break;
        case EXIT:
        	endTask(parameters[0]);
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
    // TODO: STOP PLENKING!!!
    _enable_interrupts( ) ;
}
