#include "SerialService.h"

#include "HAL/UART/UART_HAL.h"


// TODO: delete define
#define FALSE 0
#define TRUE 1
extern int init_uart_rs232_ = FALSE;





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
int printText(char* text);
void SerialService::run() {
	char buffer[1];
	buffer[0] = ' ';
	read(1, buffer);
	printText(&buffer[0]);
	
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


/** delete THIS!!!!!!!!!!!!!!! **/


#include "Tasks/Services/Display/Graphics.h"
#include "HAL/Display/HalDisplayDriver.h"
#define WIDTH 1024
#define HEIGHT 768
#define RES_WIDTH 1024
#define RES_HEIGHT 768
#define FBADDR ((char *)0x83000000)

int printText(char* text)  {
	/*RastPort *rp;

	HalDisplayDriver::video_init(); // --> video.c
	rp = Graphics::graphics_init(FBADDR, RES_WIDTH, RES_HEIGHT, BM_RGB16); // graphics.c
	HalDisplayDriver::omap_attach_framebuffer(0, rp->drawable.bitmap); // --> video.c

	Graphics::moveTo(rp, 0, 0);
	Graphics::setColour(rp, 0xFF007F);
	Graphics::drawRect(rp, WIDTH, HEIGHT);

	Graphics::setColour(rp, 0x00000000);

	Graphics::moveTo(rp, 20, 20);
	Graphics::drawString(rp, text, 6);*/
	
	return 0;
}
