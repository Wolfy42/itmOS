
#include "UserInput.h"
#include "serviceCalls.h"

int waitForInput() {
    int params[] = {BUTTON_SERVICE_CALL};
    performServiceCall(params);
    return 1;
}
