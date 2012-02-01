#include "Service-API/Display/Display.h"
#include "Service-API/Button/Button.h"

int ____main() {
    while(true) {
        waitForButtonPress();
        switchTask();
    }
}
