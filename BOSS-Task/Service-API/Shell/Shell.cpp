#include "Shell.h"
#include "API/systemCalls.h"


void nextChar(char* ch) {
	
	int params[] = {NEXT_CHAR, (int)(*ch)};
	performServiceCall(SHELL_SERVICE_ID, 2, params);
}
