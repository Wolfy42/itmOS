#include "Service-API/Display/Display.h"
#include "Service-API/Button/Button.h"

int main__() {
    while(true) {
        waitForButtonPress();
        switchTask();
    }
}
