
#include "UserInput.h"
#include "serviceCalls.h"

int waitForInput() {
    int params[] = {BUTTON_SERVICE};
    performServiceCall(params);
    return 1;
}
