#include "../bitOperations.h"
#include "LEDClass.h"

LEDClass::LEDClass(int gpioNumber): m_gpio(gpioNumber, false) {
    
}

LEDClass::~LEDClass() {
}

void LEDClass::toggle() {
    m_gpio.toggle();
}
void LEDClass::switchOn() {
    m_gpio.set();
}
void LEDClass::switchOff() {
	m_gpio.unset();
}
bool LEDClass::isOn() {
    return m_gpio.read();
}
