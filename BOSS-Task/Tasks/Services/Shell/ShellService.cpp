#include "ShellService.h"
#include "Service-API/LED/LED.h"
#include "API/systemCalls.h"

#define SHELL_X_START 50
#define SHELL_X_END   1000
#define SHELL_Y_START 100
#define SHELL_Y_END   750

#define LINE_HEIGHT 27
#define COLUMN_WIDTH 12

void ShellService::executeMessage(Message* message)  {

	int* params = message->getParams();
	char* char_params = new char[message->getParamsLength()];
	
	for (int i = 1; i < message->getParamsLength(); i++) {
	
		char_params[i - 1] = params[i];	
	}

	// read or write?
	ShellServiceCommand command = (ShellServiceCommand)params[0];
	


	switch (command) {
		case NEXT_CHAR:
		
			if (char_params[0] == '\n' || char_params[0] == '\r' || char_params[0] == 13) {
                if (input.length() > 0) {
                    newLine();
                }
				executeCommand(input);
				input = "";
                newLine();
                writeLineStart();
			} else {
			
				input.append(&(char_params[0]));
				echo(char_params[0]);
			}
			break;
	}
}


void ShellService::executeCommand(std::string command) {

	if (std::strcmp("exit", command.c_str()) == 0) {
		echo('x');
		//echo("can't shut down the one and only shell.");
	} else if (std::strcmp("help", command.c_str()) == 0) {
	   echo('h');
		//echo("if you're using BOSS you should be a fkn geek and wouldn't need any help.");
	} else if (std::strcmp("led toggle 1", command.c_str()) == 0) {
        toggleLED(LED1);
    } else if (std::strcmp("led toggle 2", command.c_str()) == 0) {
        toggleLED(LED2);
    } else if (std::strcmp("led on 1", command.c_str()) == 0) {
        switchLEDOn(LED1);
    } else if (std::strcmp("led on 2", command.c_str()) == 0) {
        switchLEDOn(LED2);
    } else if (std::strcmp("led off 1", command.c_str()) == 0) {
        switchLEDOff(LED1);
    } else if (std::strcmp("led off 2", command.c_str()) == 0) {
        switchLEDOff(LED2);
    } else if (std::strcmp("led read 1", command.c_str()) == 0) {
        echo((char)(getLEDState(LED1) + '0'));
    } else if (std::strcmp("led read 2", command.c_str()) == 0) {
        echo((char)(getLEDState(LED2) + '0'));
    } else if (std::strcmp("launch test", command.c_str()) == 0) {
        int params[] = {0};
        performSystemCall(EXEC, 1, params);
    } else if (std::strcmp("launch test1", command.c_str()) == 0) {
        int params[] = {1};
        performSystemCall(EXEC, 1, params);
    }
}

void ShellService::echo(char ch) {
	
//	int length = echo.size();
//	int* params = new int[length + 1];

	
    int posX = SHELL_X_START + (_currentColumn * COLUMN_WIDTH);
    if (posX >= SHELL_X_END) {
        newLine();
        posX = SHELL_X_START;
    }
    
    int posY = SHELL_Y_START + (_currentLine * LINE_HEIGHT);
    if (posY > SHELL_Y_END) {
        setColor(0x0);
        moveTo(SHELL_X_START, SHELL_Y_START - (LINE_HEIGHT + 5));
        drawRect(SHELL_X_END, SHELL_Y_END);
        _currentColumn = 0;
        _currentLine = 0;
        posY = SHELL_Y_START;
        posX = SHELL_X_START;
    }
    while (!hasScreen());
    setColor(0xFFFFFF);
	moveTo(posX, posY);
    drawChar(ch, 2);
    _currentColumn++;
    
//	params[0] = 0; //  HDMI WRITE COMMAND :)
//	for (int i = 0; i < length; i++) {
//		params[i + 1] = (int)(echo.c_str()[i]);
//	}
//	performServiceCall(DISPLAY_SERVICE_ID, 2, params);
}

void ShellService::writeLineStart() {
    echo('B');
    echo('O');
    echo('S');
    echo('S');
    echo('>');
}
void ShellService::newLine() {
    _currentColumn = 0;
    _currentLine++;
}

ShellService::ShellService() {
    writeLineStart();
}

ShellService::~ShellService()
{
}

