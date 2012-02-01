#include "Serial.h"
#include "API/systemCalls.h"

void nextChar(int receiver, char ch) {
	if (receiver == -1) {
		int params[] = {NEXT_CHAR, (int)ch};
		performServiceCall(SHELL_SERVICE_ID, 2, params);
	} else {	
		int params[] = {NEXT_CHAR, (int)ch};
		performServiceResponse(receiver, 2, params);
	}
}

void setActiveTask(int activeTask) {
	int params[] = {SET_ACTIVE_TASK, activeTask};
	performServiceCall(SERIAL_SERVICE_ID, 2, params);
}
