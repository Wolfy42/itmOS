#ifndef HALGPIODRIVER_H_
#define HALGPIODRIVER_H_

#include "API/dataTypes.h"

class HalGpioDriver {
    private:
        address m_oeAddress;
        address m_dataOutAddress;
        address m_setDataOutAddress;
        address m_clearDataoutAddress;
        address m_dataInAddress;
        int m_portNumber;
        int m_pinNumber;
        bool m_isInput;
        
        void initControl(address controlAddress, int controlOffset, bool isInput);
    public:
    	HalGpioDriver(int gpioPortNumber, bool isInput);
    	virtual ~HalGpioDriver();
        
        void set();
        void unset();
        void toggle();
        bool read();
};

#endif /*HALGPIODRIVER_H_*/
