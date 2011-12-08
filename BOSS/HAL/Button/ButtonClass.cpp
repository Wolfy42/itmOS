#include "Lib/bitOperations.h"
#include "ButtonClass.h"

ButtonClass::ButtonClass(int gpioNumber): m_gpio(gpioNumber, true) {
    
}

ButtonClass::~ButtonClass() {
}

bool ButtonClass::isPressed() {
    return m_gpio.read();
}
