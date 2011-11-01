#ifndef BUTTONDRIVER_H_
#define BUTTONDRIVER_H_

#include "../Driver.h"

class ButtonDriver : public Driver {
    public:
    	ButtonDriver();
    	virtual ~ButtonDriver();
        
        virtual void init();
        virtual void write(byte value[]);
        virtual byte* read(byte position[]);
};

#endif /*BUTTONDRIVER_H_*/
