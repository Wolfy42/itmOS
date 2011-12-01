#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "Driver/LED/LEDDriver.h"
#include "Tasks/UserModeTask.h"
#include "BOSSAPI/serviceCalls.h"

class LEDService : public UserModeTask {

	private:
		LEDDriver _driver;
		
		virtual void executeMessage(Message* message);

		void switchLEDOn(LED led);
		void switchLEDOff(LED led);
		void toggleLED(LED led);
		LEDState getLEDState(LED led);

	public:
		LEDService();
		virtual ~LEDService();

		virtual MessageQueue* getQueue();
};

#endif /*LEDSERVICE_H_*/
