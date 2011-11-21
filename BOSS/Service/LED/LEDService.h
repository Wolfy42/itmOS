#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "Driver/LED/LEDDriver.h"
#include "Service/Service.h"
#include "BOSSAPI/serviceCalls.h"

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
		
        virtual void command(int params[]);
		virtual bool stop();
};

#endif /*LEDSERVICE_H_*/
