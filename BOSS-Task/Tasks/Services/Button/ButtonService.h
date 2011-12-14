#ifndef BUTTONSERVICE_H_
#define BUTTONSERVICE_H_

#include "HAL/Button/HALButtonDriver.h"

//TODO: this class needs refactoring: create a service

class ButtonService  {
        
    public:
    	ButtonService();
    	virtual ~ButtonService();

        virtual void execute(int params[]);
};

#endif /*BUTTONSERVICE_H_*/
