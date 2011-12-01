#ifndef BUTTONSERVICE_H_
#define BUTTONSERVICE_H_

#include "BOSSAPI/serviceCalls.h"
#include "Driver/Button/ButtonDriver.h"

//TODO: This class needs a refactoring

class ButtonService  {
    private:
        ButtonDriver m_buttonDriver;
        bool m_running;
        
    protected:
        virtual void start();
        
    public:
    	ButtonService();
    	virtual ~ButtonService();

    	virtual int getServiceId();
        virtual void execute(int params[]);
        
        virtual bool stop();
};

#endif /*BUTTONSERVICE_H_*/
