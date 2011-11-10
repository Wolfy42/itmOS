
#include "UserInput.h"
#include <API/serviceCalls.h>

int waitForInput() {
    int params[] = {BUTTON_SERVICE_CALL};
    performServiceCall(params);
    return 1;
}
