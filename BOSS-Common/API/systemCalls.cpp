#include "API/systemCalls.h"

void performSystemCall(int systemCallId)  {
	int* params = new int[1];
	params[0] = systemCallId;

    swi(params);
    delete params;
}

void performSystemCall(int systemCallId, int para1)  {
	int* params = new int[2];
	params[0] = systemCallId;
	params[1] = para1;

    swi(params);
    delete params;
}

void performServiceResponse(int callerId, int para1)  {
	int* params = new int[4];
	params[0] = WRITE_RESPONSE;
	params[1] = callerId;
	params[2] = 1;
	params[3] = para1;

	swi(params);
    delete params;
}

void performServiceCall(int serviceId, int para1, int para2)  {
	int* params = new int[4];
	params[0] = WRITE;
	params[1] = serviceId;
	params[2] = 2;
	params[3] = para1;
	params[4] = para2;

	swi(params);
    delete params;
}
