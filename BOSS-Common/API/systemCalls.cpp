#include "API/systemCalls.h"

void performSystemCall(int systemCallId)  {
    swi(systemCallId, 0, 0, 0x0);
}

void performSystemCall(int systemCallId, int length, int params[])  {
    swi(systemCallId, 0, length, params);
}

void performServiceCall(int serviceId, int length, int params[])  {
    swi(WRITE, serviceId, length, params);
}
