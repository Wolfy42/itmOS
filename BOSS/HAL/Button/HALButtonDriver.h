#ifndef HALBUTTONDRIVER_H_
#define HALBUTTONDRIVER_H_

#include "ButtonClass.h"

#define USER_BUTTON_PIN 7

class HalButtonDriver {
    private:
        ButtonClass m_userButton;
        
    public:
    	HalButtonDriver();
    	virtual ~HalButtonDriver();
        
        bool isPressed();
};

#endif /*HALBUTTONDRIVER_H_*/
