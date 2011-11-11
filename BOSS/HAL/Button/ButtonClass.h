#ifndef BUTTONCLASS_H_
#define BUTTONCLASS_H_

#include "API/dataTypes.h"
#include "HAL/GPIO/HalGpioDriver.h"

class ButtonClass {
    private:
        HalGpioDriver m_gpio;
        
    public:
    	ButtonClass(int gpioNumber);
    	virtual ~ButtonClass();
        
        bool isPressed();
};

#endif /*BUTTONCLASS_H_*/
