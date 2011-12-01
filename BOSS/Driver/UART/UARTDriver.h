#ifndef UARTDRIVER_H_
#define UARTDRIVER_H_


#include "Driver/Driver.h"

#include "HAL/UART/UART_HAL.h"


class UARTDriver
{
public:
	UARTDriver();
	virtual ~UARTDriver();
	
    virtual void init();
    virtual void write(int count, char* buffer);
	int read(int count, char* buffer);
};

#endif /*UARTDRIVER_H_*/
