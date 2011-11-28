#include "HAL/gpio.h"
#include "HAL/control.h"
#include "Lib/bitOperations.h"
#include "HalGpioDriver.h"

HalGpioDriver::HalGpioDriver(int gpioNumber, bool isInput): m_isInput(isInput), m_portNumber((gpioNumber / 32) + 1), m_pinNumber(gpioNumber % 32) {
    
    switch (m_portNumber) {
        case 1:
            m_oeAddress = GPIO_OE_GPIO1;
            m_dataOutAddress = GPIO_DATAOUT_GPIO1;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO1;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO1;
            m_dataInAddress = GPIO_DATAIN_GPIO1;
            break;        
        case 2:
            m_oeAddress = GPIO_OE_GPIO2;
            m_dataOutAddress = GPIO_DATAOUT_GPIO2;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO2;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO2;
            m_dataInAddress = GPIO_DATAIN_GPIO2;
            break;
        case 3:
            m_oeAddress = GPIO_OE_GPIO3;
            m_dataOutAddress = GPIO_DATAOUT_GPIO3;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO3;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO3;
            m_dataInAddress = GPIO_DATAIN_GPIO3;
            break;
        case 4:
            m_oeAddress = GPIO_OE_GPIO4;
            m_dataOutAddress = GPIO_DATAOUT_GPIO4;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO4;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO4;
            m_dataInAddress = GPIO_DATAIN_GPIO4;
            break;
        case 5:
            m_oeAddress = GPIO_OE_GPIO5;
            m_dataOutAddress = GPIO_DATAOUT_GPIO5;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO5;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO5;
            m_dataInAddress = GPIO_DATAIN_GPIO5;
            break;
        case 6:
            m_oeAddress = GPIO_OE_GPIO6;
            m_dataOutAddress = GPIO_DATAOUT_GPIO6;
            m_setDataOutAddress = GPIO_SETDATAOUT_GPIO6;
            m_clearDataoutAddress = GPIO_CLEARDATAOUT_GPIO6;
            m_dataInAddress = GPIO_DATAIN_GPIO6;
            break;
        default:
            break;
    }
    switch (gpioNumber) {
        case 7:
            initControl(CONTROL_GPIO_7, 0, isInput);
            break;
        case 149:
            initControl(CONTROL_GPIO_149, 0, isInput);
            break;
        case 150:
            initControl(CONTROL_GPIO_150, 16, isInput);
            break;
        default:
            break;
    }
}


HalGpioDriver::~HalGpioDriver() {
}

void HalGpioDriver::initControl(address controlAddress, int controlOffset, bool isInput) {
    if (m_portNumber == 1) {
        // enable gpio1 clock
        setBit(((address)0x48004C00), 3);
        setBit(((address)0x48004C10), 3);
    }
    
    // Set MUXMODE to 4 (Binary 100)
    unsetBit(controlAddress, 0 + controlOffset);
    unsetBit(controlAddress, 1 + controlOffset);
    setBit(controlAddress, 2 + controlOffset);
    
    if (isInput) {
        // Enable pull
        setBit(controlAddress, 3 + controlOffset);
        //set to Pull Down
        unsetBit(controlAddress, 4 + controlOffset);
        
        // enable input
        setBit(controlAddress, 8 + controlOffset);
        
        setBit(m_oeAddress, m_pinNumber);
    } else {
        unsetBit(m_oeAddress, m_pinNumber);
    }
}
void HalGpioDriver::set() {
    *(m_setDataOutAddress) = (1 << m_pinNumber);
}

void HalGpioDriver::unset() {
    *(m_clearDataoutAddress) = (1 << m_pinNumber);
}
void HalGpioDriver::toggle() {
    toggleBit(m_dataOutAddress, m_pinNumber);
}

bool HalGpioDriver::read() {
    bool result = false;
    if (m_isInput) {
        result = readBit(m_dataInAddress, m_pinNumber);
    } else {
        result = readBit(m_dataOutAddress, m_pinNumber);
    }
    return result;
}
    
