#include "ShellService.h"



void ShellService::executeMessage(Message* message)  {

	int* params = message->getParams();
	char* char_params;
	
	for (int i = 1; i < message->getParamsLength(); i++) {
	
		char_params[i - 1] = params[i];	
	}

	// read or write?
	ShellServiceCommand command = (ShellServiceCommand)params[0];
	


	switch (command) {
		case NEXT_CHAR:
		
			if (char_params[0] == '\n' || char_params[0] == '\r' || char_params[0] == 13) {
			
				executeCommand(input);
				input = "";
			} else {
			
				input.append(&char_params[0]);
				echo(char_params[0]);
			}
			break;
	}
}


void ShellService::executeCommand(std::string command) {

	if (std::strcmp("exit", command.c_str()) == 0) {
		
		echo("can't shut down the one and only shell.");
	} else if (std::strcmp("help", command.c_str()) == 0) {
	
		echo("if you're using BOSS you should be a fkn geek and wouldn't need any help.");
	}
}

void ShellService::echo(std::string echo) {
	
//	int length = echo.size();
//	int* params = new int[length + 1];
	setColor(0);
	moveTo(50, 50);
	drawString(echo.c_str(), 7);
//	params[0] = 0; //  HDMI WRITE COMMAND :)
//	for (int i = 0; i < length; i++) {
//		params[i + 1] = (int)(echo.c_str()[i]);
//	}
//	performServiceCall(DISPLAY_SERVICE_ID, 2, params);
}

ShellService::ShellService()
{

}

ShellService::~ShellService()
{
}

