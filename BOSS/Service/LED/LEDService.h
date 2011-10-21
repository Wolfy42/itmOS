#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "../../Driver/LED/LEDDriver.h"
#include "../Service.h"

enum LEDServiceCommand {
	SERVICE_TOGGLE_LED,
	SERVICE_SWITCH_LED_ON,
	SERVICE_SWITCH_LED_OFF,
	SERVICE_GET_LED_STATUS
};

class LEDService : public Service {
	private:
		LEDDriver _driver;
		bool _running;
		
		void switchLEDOn(LED led);
		void switchLEDOff(LED led);
		void toggleLED(LED led);
		LEDState getLEDState(LED led);
	protected:
		virtual void start();	
	public:
		LEDService();
		virtual ~LEDService();
		
		virtual bool stop();
};


#endif /*LEDSERVICE_H_*/
