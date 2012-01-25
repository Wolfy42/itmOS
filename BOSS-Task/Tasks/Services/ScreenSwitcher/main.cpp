#include "Service-API/Display/Display.h"
#include "Service-API/Button/Button.h"

int main____() {
    while(true) {
        while(!isPressed());
        switchTask();
    }
}
