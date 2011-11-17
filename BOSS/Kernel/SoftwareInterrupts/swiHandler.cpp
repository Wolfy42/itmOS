#include "API/dataTypes.h"
#include "HAL/bitOperations.h"
#include "API/systemCalls.h"
#include "HAL/Timer/HalTimerDriver.h"
#include "Service/Service.h"
#include "HAL/gpio.h"

#define MAX_SERVICES 25
#define INIT 0x0

int serviceIds[MAX_SERVICES];
Service* services[MAX_SERVICES];
int nrOfServices = 0;

void init() {
    unsigned int i;
    address tableAddress = (address)0x40200000;
    // Set Domain Access control register to 0101 0101 0101 0101 0101 0101 0101 0101 
    asm("\t MOV r1, #0x5557\n");
    asm("\t MOVT r1, #0x5555\n");
    asm("\t MCR p15, #0, r1, c3, c0, #0\n");
    
    // Set the Master Table Pointer to the internal ram
    asm("\t MOV r1, #0x0000\n");
    asm("\t MOVT r1, #0x4020\n");
    asm("\t MCR p15, #0, r1, c2, c0, #0\n");
    
    // Initialize Master Table
    for (i = 0x00000000; i < 0xFFF00000; i += 0x00100000) {
        *tableAddress = i | 0xC12;
        tableAddress++;
    }
    *tableAddress = 0xFFF00C12;
    
    // Enable MMU
    asm("\t MRC p15, #0, r1, c1, c0, #0\n");
    asm("\t ORR r1, r1, #0x1\n");
    asm("\t MCR p15, #0, r1, c1, c0, #0\n");
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

#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI(int swiNumber, int* parameters)  {
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
    _enable_interrupts( ) ;
}
