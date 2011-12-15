#ifndef LEDSERVICE_H_
#define LEDSERVICE_H_

#include "Tasks/Services/LED/LEDConfig.h"
#include "HAL/LED/HalLedDriver.h"
#include "Tasks/Services/Service.h"

class LEDService : public Service {

	private:	
		HalLedDriver _driver;
		virtual void executeMessage(Message* message);

	public:	
		LEDService();
		virtual ~LEDService();

		// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~
		// Service-Config
		static LEDConfig CONFIG;
		
		// Service-Main
		static void main(void);
		// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~
};

#endif /*LEDSERVICE_H_*/
