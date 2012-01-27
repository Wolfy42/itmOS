#include "SerialService.h"

#include "HAL/UART/UART_HAL.h"
#include "Service-API/Shell/Shell.h"

// TODO: delete define
#define FALSE 0
#define TRUE 1
extern int init_uart_rs232_ = FALSE;





void SerialService::executeMessage(Message* message)  {

	int* params = message->getParams();
	char* char_params = new char[message->getParamsLength()];
	
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



void SerialService::run() {
	
	char buffer[1];
	buffer[0] = ' ';
	read(1, buffer);
	nextChar(buffer[0]);
	//printText(&buffer[0]);
	
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
        char c = buffer[i];
	    uart_read(uart, &c);
	
	    // stop reading when receiving a return
	    // TODO: just one char - change func?
	    //if(buffer[i] == '\r')  break;
	  }
	  return i;
}


/** delete THIS!!!!!!!!!!!!!!! **/
//
//
//#include "HAL/Display/HalDisplayDriver.h"
//
//int printText(char* text)  {
//	HalDisplayDriver* displayDriver = new HalDisplayDriver;
//
//	displayDriver->moveTo(0, 0);
//	displayDriver->setColor(0xFF007F);
//	displayDriver->drawRect(WIDTH, HEIGHT);
//
//	displayDriver->setColor(0x00000000);
//
//	displayDriver->moveTo(20, 20);
//	displayDriver->drawString(text, 6);
//	
//	return 0;
//}
