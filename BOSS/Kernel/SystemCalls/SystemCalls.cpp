
#include "BOSSAPI/systemCalls.h"
#include "BOSSAPI/serviceCalls.h"
#include "SoftwareInterrupt.h"

void performServiceCall(int params[]) {
  //  performSyscall(SERVICE_CALL, params);
}

void performSyscall(int syscallId, int parameters[]) {
    swi(syscallId, parameters);
}
