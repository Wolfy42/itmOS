#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_


#include "Driver/Driver.h"

#include "HAL/UART/UART_HAL.h"


class UARTDriver : public Driver 
{
public:
	UARTDriver();
	virtual ~UARTDriver();
	
    virtual void init();
    virtual void write(byte value[]);
    virtual byte* read(byte position[]);
};

#endif /*UARTDRIVER_H_*/
