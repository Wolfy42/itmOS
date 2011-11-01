
#include "../scm.h"
#include "../gpio.h"
#include "HALButtonDriver.h"

HALButtonDriver::HALButtonDriver(): m_userButton(GPIO_OE_GPIO1, GPIO_DATAIN_GPIO1, USER_BUTTON_PIN) {
    
}

HALButtonDriver::~HALButtonDriver() {
}

unsigned int HALButtonDriver::isPressed() {
    return m_userButton.isPressed();
}
