#include "../bitOperations.h"
#include "LEDClass.h"

LEDClass::LEDClass(address oeAddress, address registerAddress, address setRegisterAddress, address clearRegisterAddress, int bitNumber): m_oeAddress(oeAddress), m_registerAddress(registerAddress), m_setRegisterAddress(setRegisterAddress), m_clearRegisterAddress(clearRegisterAddress), m_bitNumber(bitNumber) {
    unsetBit(m_oeAddress, m_bitNumber);
}

LEDClass::~LEDClass() {
}

void LEDClass::toggle() {
    toggleBit(m_registerAddress, m_bitNumber);
}
void LEDClass::switchOn() {
    *(m_setRegisterAddress) = (1 << m_bitNumber);
}
void LEDClass::switchOff() {
	*(m_clearRegisterAddress) = (1 << m_bitNumber);
}
bool LEDClass::isOn() {
    return readBit(m_registerAddress, m_bitNumber);
}
