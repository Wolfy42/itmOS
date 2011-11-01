#include "ButtonDriver.h"

ButtonDriver::ButtonDriver() {
}

ButtonDriver::~ButtonDriver() {
}

void ButtonDriver::init() {
}
void ButtonDriver::write(byte value[]) {
}
byte* ButtonDriver::read(byte position[]) {
    // There is only one button so position is ignored. Can be expanded later
    byte result[] = {(byte)m_halDriver.isPressed()};
    byte* pointer = result;
    return pointer;
}
