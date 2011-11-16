#include "../../API/dataTypes.h"
#include "../../API/systemCalls.h"
#include "../../HAL/Timer/HalTimerDriver.h"
#include "../../Service/Service.h"

#include "Kernel/TaskManagement/Tasks.h"

#define MAX_SERVICES 25
#define INIT 0x0

int serviceIds[MAX_SERVICES];
Service* services[MAX_SERVICES];
int nrOfServices = 0;

void init() {
    address clear1 = (address)0x482000A8;
    *(clear1) |= (1 << 6);

    HalTimerDriver dr;
}

void registerService(int params[]) {
    serviceIds[nrOfServices] = params[0];
    services[nrOfServices] = (Service*)params[1];
    nrOfServices++;
}
void callService(int params[]) {
    int serviceId = params[0];
    int index = -1;
    int currentIndex = 0;
    while ((currentIndex < nrOfServices) && (index < 0)) {
        if (serviceIds[currentIndex] == serviceId) {
            index = currentIndex;
        }
        currentIndex++;
    }
    if (index >= 0) {
        services[index]->command(params);
    }

}

void endTask(TID_t id) {
	
	deleteTask(id);
	//yield();
	activeTask = -1;
	_enable_interrupts();
	while (1) {
		
	}
}

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
        case REGISTER_SERVICE:
            registerService(parameters);
            break;
        case SERVICE_CALL:
            callService(parameters);
            break;
        case SERVICE_RESPONSE:
            break;
        default:
            break;
    }
    // TODO: STOP PLENKING!!!
    _enable_interrupts( ) ;
}
