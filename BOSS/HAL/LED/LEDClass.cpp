#include "LEDClass.h"
#include "../gpio.h"

LEDClass::LEDClass(int bitNumber): m_bitNumber(bitNumber) {
}

LEDClass::~LEDClass()
{
}

void LEDClass::toggle() {
	GPIO_OE_GPIO5 ^= (1 << m_bitNumber);
}
void LEDClass::switchOff() {
	GPIO_OE_GPIO5 |= (1 << m_bitNumber);
}
void LEDClass::switchOn() {
	GPIO_OE_GPIO5 &= ~(1 << m_bitNumber);
}
bool LEDClass::isOff() {
	return (GPIO_OE_GPIO5 & (1 << m_bitNumber));
}
