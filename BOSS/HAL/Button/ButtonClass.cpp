#include "../control.h"
#include "../bitOperations.h"
#include "ButtonClass.h"

ButtonClass::ButtonClass(address oeAddress, address registerAddress, int bitNumber): m_oeAddress(oeAddress), m_registerAddress(registerAddress), m_bitNumber(bitNumber) {
    // enable gpio1 clock
    setBit(((address)0x48004C00), 3);
    setBit(((address)0x48004C10), 3);
    // Set MUXMODE to 4 (Binary 100)
    unsetBit(CONTROL_GPIO_7, 0);
    unsetBit(CONTROL_GPIO_7, 1);
    setBit(CONTROL_GPIO_7, 2);
    
    // Enable pull
    setBit(CONTROL_GPIO_7, 3);
    //set to Pull Down
    unsetBit(CONTROL_GPIO_7, 4);
    
    // enable input
    setBit(CONTROL_GPIO_7, 8);
    
    setBit(m_oeAddress, m_bitNumber);
}

ButtonClass::~ButtonClass() {
}

bool ButtonClass::isPressed() {
    return (*(m_registerAddress) & (1 << m_bitNumber));
}
