#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "HAL/LED/HalLedDriver.h"
#include "Tasks/UserModeTask.h"

void led_main(void);

class LEDService : public UserModeTask {

	private:
		HalLedDriver _driver;
		virtual void executeMessage(Message* message);

	public:
		LEDService();
		virtual ~LEDService();

		virtual MessageQueue* getQueue();
};

#endif /*LEDSERVICE_H_*/
