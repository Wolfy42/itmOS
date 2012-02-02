#include "API/systemCalls.h"
#include "API/Semaphore.h"

void performSystemCall(int systemCallId)  {
    swi(systemCallId, 0, 0, 0x0);
}

void performSystemCall(int systemCallId, int length, int params[])  {
    swi(systemCallId, 0, length, params);
}

void performServiceCall(int serviceId, int length, int params[])  {
    enterSemaphore(SERVICE_ID, serviceId);
    swi(WRITE, serviceId, length, params);
    exitSemaphore(SERVICE_ID, serviceId);
    
    int parameters[] = {SERVICE_ID, serviceId};
    performSystemCall(NOTIFY, 2, parameters);
}

void performServiceResponse(int callerId, int length, int params[])  {
    enterSemaphore(TASK_ID, callerId);
	swi(WRITE_RESPONSE, callerId, length, params);
    exitSemaphore(TASK_ID, callerId);
    
    int parameters[] = {TASK_ID, callerId};
    performSystemCall(NOTIFY, 2, parameters);
}
