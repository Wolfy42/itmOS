
#include "../API/systemCalls.h"
#include "../API/serviceCalls.h"

void performServiceCall(byte params[]) {
    performSyscall(SERVICE_CALL, params);
}

void performSyscall(int syscallId, byte parameters[]) {
    // TODO perform Syscall
}
