#ifndef HALLEDDRIVER_H_
#define HALLEDDRIVER_H_

#include "LEDClass.h"
#include <BOSSAPI/LEDConstants.h>

class HalLedDriver {
	private:
		LEDClass m_led1;
		LEDClass m_led2;
		
		LEDClass ledClassForEnum(LED ledEnum);
	public:
		HalLedDriver();
		virtual ~HalLedDriver();
		
		void init();
		void ledOn(LED led);
		void ledOff(LED led);
		void toggle(LED led);
		bool isOn(LED led);
};

#endif /*HALLEDDRIVER_H_*/
