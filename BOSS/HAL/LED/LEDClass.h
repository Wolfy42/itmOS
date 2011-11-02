#ifndef LED_H_
#define LED_H_

#include "../../API/dataTypes.h"

class LEDClass {
	private:
        address m_oeAddress;
        address m_registerAddress;
        address m_setRegisterAddress;
        address m_clearRegisterAddress;
		int m_bitNumber;
	
	public:
		LEDClass(address oeAddress, address registerAddress, address setRegisterAddress, address clearRegisterAddress, int bitNumber);
		virtual ~LEDClass();
		
		void toggle();
		void switchOn();
		void switchOff();
		bool isOn();
};

#endif /*LED_H_*/
