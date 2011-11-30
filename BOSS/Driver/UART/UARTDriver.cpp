#include "UARTDriver.h"

// TODO: delete define
#define FALSE 0
#define TRUE 1
extern int init_uart_rs232_ = FALSE;





UARTDriver::UARTDriver()
{
}

UARTDriver::~UARTDriver()
{
}



void UARTDriver::init() {
	
	if (init_uart_rs232_ == FALSE) {
	    uart_init((mem_address_t*) UART3, UART_MODE_16X, uart_protocol_rs232,
	            UART_FLOW_CONTROL_DISABLE_FLAG);
	    init_uart_rs232_ = TRUE;
	    return;
	}
	return;
}



void UARTDriver::write(byte value[]) {
	
	mem_address_t* uart = (mem_address_t*) UART3;
	int i = 0;
	int count = value[0];
	char* buffer = (char*)value[1];
	
	for (; i < count; i++, buffer++) {
	// block while queue is full
	   while (!uart_is_empty_write_queue(uart))
	     ;
	   uart_write(uart, buffer);
	}
	
	return;
}


byte* UARTDriver::read(byte position[]) {
     mem_address_t* uart = (mem_address_t*)UART3;
    int i = 0;
	int count = position[0];
	char* buffer = (char*)position[1];

  for (; i < count; i++, buffer++) {
    // block while waiting for data
    while (uart_is_empty_read_queue(uart))
      ;
    uart_read(uart, buffer);
  }
  return (byte*)position[1];
}