#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "Driver/LED/LEDDriver.h"
#include "Service/Service.h"
#include "BOSSAPI/serviceCalls.h"

class LEDService : public Service {

	private:
		LEDDriver _driver;
		
		virtual void execute(int params[]);

		void switchLEDOn(LED led);
		void switchLEDOff(LED led);
		void toggleLED(LED led);
		LEDState getLEDState(LED led);

	public:
		LEDService();
		virtual ~LEDService();
		
		virtual int getServiceId();
};

#endif /*LEDSERVICE_H_*/
