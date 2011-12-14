#ifndef HALLEDDRIVER_H_
#define HALLEDDRIVER_H_

#include "LEDClass.h"
#include "Service-API/LED/LED.h"

class HalLedDriver {
	private:
		LEDClass _led1;
		LEDClass _led2;

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
