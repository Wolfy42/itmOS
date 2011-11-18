#ifndef HALLEDDRIVER_H_
#define HALLEDDRIVER_H_

#include "LEDClass.h"
#include "BOSSAPI/LEDConstants.h"

class HalLedDriver {
	private:
		static HalLedDriver LED_DRIVER;
		
		HalLedDriver();
		virtual ~HalLedDriver();
		
		LEDClass m_led1;
		LEDClass m_led2;
		
		LEDClass ledClassForEnum(LED ledEnum);
		
	public:		
		static void init();
		static void ledOn(LED led);
		static void ledOff(LED led);
		static void toggle(LED led);
		static bool isOn(LED led);
};

#endif /*HALLEDDRIVER_H_*/
