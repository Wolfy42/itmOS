#ifndef BUTTONSERVICE_H_
#define BUTTONSERVICE_H_

#include "Service-API/Button/Button.h"
#include "Tasks/Services/Service.h"
#include "HAL/Button/HALButtonDriver.h"

#define MAX_LISTENERS 20

class ButtonService : public Service {
    private:
        HalButtonDriver _buttonDriver;
        bool _buttonIsPressed;
        
        int _listeningTasks[MAX_LISTENERS];
        
        bool isTaskListening(int taskId);
        int findFreeSlot();
        int findTaskId(int taskId);
        
        void fireEvent();
    public:
    	ButtonService();
    	virtual ~ButtonService();

        virtual void run();
        virtual void executeMessage(Message* message);
};

#endif /*BUTTONSERVICE_H_*/
