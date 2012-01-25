#ifndef BUTTONSERVICE_H_
#define BUTTONSERVICE_H_

#include "Tasks/Services/Service.h"
#include "HAL/Button/HALButtonDriver.h"

//TODO: this class needs refactoring: create a service

class ButtonService : public Service {
    private:
        HalButtonDriver _buttonDriver;
    public:
    	ButtonService();
    	virtual ~ButtonService();

        virtual void executeMessage(Message* message);
};

#endif /*BUTTONSERVICE_H_*/
