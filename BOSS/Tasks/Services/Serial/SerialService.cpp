#include "SerialService.h"

#include "HAL/UART/UART_HAL.h"

// TODO: delete define
#define FALSE 0
#define TRUE 1
extern int init_uart_rs232_ = FALSE;


// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~
SerialConfig SerialService::CONFIG = SerialConfig();

// Static main method for this service
void SerialService::main(void) {
	SerialService service;
	service.run();
}
// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~


MessageQueue* SerialService::getQueue()  {
	return *(MessageQueue**)0x820F0000;
}

void SerialService::executeMessage(Message* message)  {

	int* params = message->getParams();
	char* char_params;
	
	for (int i = 1; i < message->getParamsLength(); i++) {
	
		char_params[i - 1] = params[i];	
	}

	// read or write?
	SerialCommand command = (SerialCommand)params[0];
	


	switch (command) {
		case SERIAL_WRITE:
			write(message->getParamsLength() - 1, char_params);
			break;
		case SERIAL_READ:
			// single character response
//			int response[1];
//			uart.read(1, response);
//			response[0]
//			writeResponse(response);
			break;
	}
}




SerialService::SerialService()
{
	
	init();
}

SerialService::~SerialService()
{
}



void SerialService::init() {
	
	if (init_uart_rs232_ == FALSE) {
	    uart_init((mem_address_t*) UART3, UART_MODE_16X, uart_protocol_rs232,
	            UART_FLOW_CONTROL_DISABLE_FLAG);
	    init_uart_rs232_ = TRUE;
	    return;
	}
	return;
}



void SerialService::write(int count, char* buffer) {
	
	mem_address_t* uart = (mem_address_t*) UART3;
	int i = 0;
	
	for (; i < count; i++, buffer++) {
	// block while queue is full
	   while (!uart_is_empty_write_queue(uart))
	     ;
	   uart_write(uart, buffer);
	}
	
	return;
}


int SerialService::read(int count, char* buffer) {
	
	  mem_address_t* uart = (mem_address_t*)UART3;
	  int i = 0;
	
	  for (; i < count; i++) {
	    // block while waiting for data
	    while (uart_is_empty_read_queue(uart))
	      ;
	    uart_read(uart, &buffer[i]);
	
	    // stop reading when receiving a return
	    // TODO: just one char - change func?
	    //if(buffer[i] == '\r')  break;
	  }
	  return i;
}
