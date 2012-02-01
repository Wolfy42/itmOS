#include "Service-API/Display/Display.h"
#include "Service-API/Button/Button.h"

int main_ScSw() {
    while(true) {
        waitForButtonPress();
        switchTask();
    }
}
