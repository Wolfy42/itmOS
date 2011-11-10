#ifndef LEDCLASS_H_
#define LEDCLASS_H_

#include <API/dataTypes.h>
#include <HAL/GPIO/HalGpioDriver.h>

class LEDClass {
	private:
        HalGpioDriver m_gpio;    
	
	public:
		LEDClass(int gpioNumber);
		virtual ~LEDClass();
		
		void toggle();
		void switchOn();
		void switchOff();
		bool isOn();
};

#endif /*LEDCLASS_H_*/
