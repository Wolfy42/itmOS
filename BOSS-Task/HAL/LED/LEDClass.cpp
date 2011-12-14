#include "Lib/bitOperations.h"
#include "LEDClass.h"

LEDClass::LEDClass(int gpioNumber): _gpio(gpioNumber, false) {
    
}

LEDClass::~LEDClass() {
}

void LEDClass::toggle() {
    _gpio.toggle();
}
void LEDClass::switchOn() {
    _gpio.set();
}
void LEDClass::switchOff() {
	_gpio.unset();
}
bool LEDClass::isOn() {
    return _gpio.read();
}
