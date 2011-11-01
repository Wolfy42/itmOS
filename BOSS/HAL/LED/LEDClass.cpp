#include "LEDClass.h"

LEDClass::LEDClass(address oeAddress, address registerAddress, address setRegisterAddress, address clearRegisterAddress, int bitNumber): m_oeAddress(oeAddress), m_registerAddress(registerAddress), m_setRegisterAddress(setRegisterAddress), m_clearRegisterAddress(clearRegisterAddress), m_bitNumber(bitNumber) {
    *(m_oeAddress) &= ~(1 << m_bitNumber);
}

LEDClass::~LEDClass() {
}

void LEDClass::toggle() {
    *(m_registerAddress) ^= (1 << m_bitNumber);
}
void LEDClass::switchOn() {
    *(m_setRegisterAddress) = (1 << m_bitNumber);
}
void LEDClass::switchOff() {
	*(m_clearRegisterAddress) = (1 << m_bitNumber);
}
bool LEDClass::isOn() {
	return ((*(m_registerAddress)) & (1 << m_bitNumber));
}
