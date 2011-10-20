#ifndef LEDDRIVER_H_
#define LEDDRIVER_H_

#include "../Driver.h"
#include "../../HAL/LED/HalLEDDriver.h"

enum LEDState {
	LED_OFF = 0,
	LED_ON = 1
};

enum LEDCommand {
	SWITCH_LED_OFF = 0,
	SWITCH_LED_ON = 1,
	TOGGLE_LED = 2
};

/*
 * Format:
 * 	write({(enum LED), (enum LEDCommand)}
 *  read({(enum LED)}) => {(enum LEDState)}
 */
class LEDDriver : public Driver {
	private:
		HalLedDriver m_driver;
	public:
		LEDDriver();
		virtual ~LEDDriver();
		
		virtual void init();
		virtual void write(byte value[]);
		virtual byte* read(byte position[]);
};

#endif /*LEDDRIVER_H_*/
