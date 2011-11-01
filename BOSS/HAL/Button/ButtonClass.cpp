#include "ButtonClass.h"

ButtonClass::ButtonClass(address oeAddress, address registerAddress, int bitNumber): m_oeAddress(oeAddress), m_registerAddress(registerAddress), m_bitNumber(bitNumber) {
    //*(m_oeAddress) |= (1 << m_bitNumber);
}

ButtonClass::~ButtonClass() {
}

bool ButtonClass::isPressed() {
    bool result = (*(m_registerAddress) & (1 << m_bitNumber));
}
