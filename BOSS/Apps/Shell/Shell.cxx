#include "Shell.h"

#include <string.h>

#include "API/systemCalls.h"
#include "ShellApps/Task.h"

static TaskManager* _tm;

void ts() {

	showTasks(_tm);	
}

void shell(TaskManager* tm) {
	
	_tm = tm;
	char buffer[1];
	char command[1024];
	int i = 0;
	
	//TOOD: This is broken
//
//	UARTDriver uart = UARTDriver();
//	uart.init();
//
//
//	echo("\r\n\r\n*** Shell de BOSS ***\r\n");
//
//
//	while (1) {
//
//		// reset buffer
//		buffer[0] = ' ';
//
//		echo("\r\nBOSS # ");
//
//
//		// get command
//		for (i = 0; buffer[0] != '\r'; i++) {
//			uart.read(1, buffer);
//
//
//			// add next letter to command
//			command[i] = buffer[0];
//		}
//
//		// replace \r with \0
//		command[--i] = '\0';
//
//
//		if(std::strcmp("exit", command) == 0) {
//			echo("Bye Bye\n");
//			break;
//    	}
//
//    	if(std::strcmp("ts", command) == 0) {
//
//			tm->create("ts", 100, (int)ts, true);
//			performSyscall(YIELD, NULL);
//    	}
//  	}
}

