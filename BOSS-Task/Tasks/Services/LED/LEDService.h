#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "HAL/LED/HalLedDriver.h"
#include "Tasks/Services/Service.h"

class LEDService : public Service {

	private:	
		HalLedDriver _driver;
		virtual void executeMessage(Message* message);

	public:	
		LEDService();
		virtual ~LEDService();
};

#endif /*LEDSERVICE_H_*/
