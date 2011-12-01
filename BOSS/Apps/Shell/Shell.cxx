#include "Shell.h"

#include "Driver/UART/UARTDriver.h"
#include <string.h>

void shell() {
	
	char* display_text;
	char buffer[1];
	char command[1024];
	int i = 0;
	
	UARTDriver uart = UARTDriver();
	uart.init();

	
	display_text = "\r\n\r\n*** Shell de BOSS ***\r\n";
	uart.write(std::strlen(display_text), display_text);

	while (1) {
	
		// reset buffer
		buffer[0] = ' ';
	
		display_text = "\r\nBOSS # ";
		uart.write(std::strlen(display_text), display_text);
		
		// get command
		for (i = 0; buffer[0] != '\r'; i++) {
			uart.read(1, buffer);
			
			// write it again to shell
			uart.write(1, &buffer[0]);
			
			// add next letter to command
			command[i] = buffer[0];
		}

		// replace \r with \0
		command[--i] = '\0';
		
		
		if(std::strcmp("exit", command) == 0) {
			display_text = "\r\nBye Bye (wave)\r\n";
			uart.write(std::strlen(display_text), display_text);
			break;
    	}
  	}
}
