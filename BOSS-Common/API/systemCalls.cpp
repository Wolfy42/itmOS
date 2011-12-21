#include "API/systemCalls.h"

void performSystemCall(int systemCallId)  {
    swi(systemCallId, 0, 0, 0, 0, 0, 0, 0);
}

void performSystemCall(int systemCallId, int para1)  {
    swi(systemCallId, para1, 0, 0, 0, 0, 0, 0);
}

void performServiceCall(int serviceId, int para1, int para2)  {
    swi(WRITE, serviceId, 2, para1, para2, 0, 0, 0);
}
