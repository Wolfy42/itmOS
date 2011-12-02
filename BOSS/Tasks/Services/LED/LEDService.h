#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "HAL/LED/HalLedDriver.h"
#include "Tasks/UserModeTask.h"

class LEDService : public UserModeTask {

	private:
		virtual void executeMessage(Message* message);

	public:
		LEDService();
		virtual ~LEDService();

		virtual MessageQueue* getQueue();
};

#endif /*LEDSERVICE_H_*/
