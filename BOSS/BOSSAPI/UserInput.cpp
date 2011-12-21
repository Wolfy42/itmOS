
#include "UserInput.h"

int waitForInput() {
    int params[] = {BUTTON_SERVICE};
    performServiceCall(params);
    return 1;
}
