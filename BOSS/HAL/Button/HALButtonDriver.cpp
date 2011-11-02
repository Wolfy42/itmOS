#include "../control.h"
#include "../gpio.h"
#include "HALButtonDriver.h"

HalButtonDriver::HalButtonDriver(): m_userButton(GPIO_OE_GPIO1, GPIO_DATAIN_GPIO1, USER_BUTTON_PIN) {
    
}

HalButtonDriver::~HalButtonDriver() {
}

bool HalButtonDriver::isPressed() {
    return m_userButton.isPressed();
}
