#ifndef HALBUTTONDRIVER_H_
#define HALBUTTONDRIVER_H_

#include "ButtonClass.h"

#define USER_BUTTON_PIN 7

class HALButtonDriver {
    private:
        ButtonClass m_userButton;
        
    public:
    	HALButtonDriver();
    	virtual ~HALButtonDriver();
        
        unsigned int isPressed();
};

#endif /*HALBUTTONDRIVER_H_*/
