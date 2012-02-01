#include "API/systemCalls.h"
#include "API/Semaphore.h"

void performSystemCall(int systemCallId)  {
    swi(systemCallId, 0, 0, 0x0);
}

void performSystemCall(int systemCallId, int length, int params[])  {
    swi(systemCallId, 0, length, params);
}

void performServiceCall(int serviceId, int length, int params[])  {
    enterSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, serviceId);
    swi(WRITE, serviceId, length, params);
    exitSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, serviceId);
}

void performServiceResponse(int callerId, int length, int params[])  {
    enterSemaphore(SEMAPHORE_TASK_MESSAGE_QUEUE, callerId);
	swi(WRITE_RESPONSE, callerId, length, params);
    exitSemaphore(SEMAPHORE_TASK_MESSAGE_QUEUE, callerId);
}
