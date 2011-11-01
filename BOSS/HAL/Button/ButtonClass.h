#ifndef BUTTONCLASS_H_
#define BUTTONCLASS_H_

#include "../../API/dataTypes.h"

class ButtonClass {
    private:
        address m_oeAddress;
        address m_registerAddress;
        int m_bitNumber;
        
    public:
    	ButtonClass(address oeAddress, address registerAddress, int bitNumber);
    	virtual ~ButtonClass();
        
        bool isPressed();
};

#endif /*BUTTONCLASS_H_*/
