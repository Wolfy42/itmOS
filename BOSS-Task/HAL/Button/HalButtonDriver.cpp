#include "HALButtonDriver.h"

HalButtonDriver::HalButtonDriver(): m_userButton(7) {
    
}

HalButtonDriver::~HalButtonDriver() {
}

bool HalButtonDriver::isPressed() {
    return m_userButton.isPressed();
}
