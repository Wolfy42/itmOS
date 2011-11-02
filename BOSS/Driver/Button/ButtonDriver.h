#ifndef BUTTONDRIVER_H_
#define BUTTONDRIVER_H_

#include "../../HAL/Button/HALButtonDriver.h"
#include "../Driver.h"

class ButtonDriver : public Driver {
    private:
        HalButtonDriver m_halDriver;
    public:
    	ButtonDriver();
    	virtual ~ButtonDriver();

        virtual void init();
        virtual void write(byte value[]);
        virtual byte* read(byte position[]);
};

#endif /*BUTTONDRIVER_H_*/
