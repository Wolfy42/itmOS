#include "Shell.h"
#include "API/systemCalls.h"


void nextChar(int ch) {
	
	int params[] = {NEXT_CHAR, ch};
	performServiceCall(SHELL_SERVICE_ID, 2, params);
}
