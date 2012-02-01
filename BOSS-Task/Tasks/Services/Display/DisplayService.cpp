#include "DisplayService.h"

DisplayService::DisplayService() : Service(), _currentTaskId(-1) {	
	// Background
	_driver.moveTo(0, 0);
	_driver.setColor(0x000A91);
	_driver.drawRect(WIDTH, HEIGHT);

	// ASCII Image
	_driver.setColor(0x00000000);
	_driver.moveTo(20, 200);
	_driver.drawString(" .  . . ................................................. M.....................\n .. . ........ ..... .   . .. .. . . . . .  .. . .   ...NMMM8.  .. . .   ... . .\n .. . ........ ..... .   . .. .. . . . . .  .. . .   .+MMMMMMM. .. . .   ... . .\n .  .    ... . . ... .   .         . .   .   .   .   MMMMMMMMMMM..   .     . .  \n..... . .... .   ... .               .   .       . ZMMMMMMMMMMMMM~.  .     . .  \n .... . ...... ..... .   . .. .. . . . . .  .. .. MMMMMMMMMMMMMMMMM ..   ... ...\n  ........ ..    ..    . .       .       . . .  ~MMMMMMMMMMMMMMMMMMMM.   .   .  \n    ........... ........ .... .... .... ........  MMMMMMMMMMMMMMMMMMMM:.........\n  ........ .. . ..    ..  .     .   .             .MMMMMMMMMMMMMMMMMMMMM.       \n    ......  .             .     .   .    .   .  .~MMMMMMMMMMMMMMMMMMMMMMM+.  .  \n ..NNNNNNNO.NNN.....NN.8NNN . ..NNN,... .... ...MMMMMMMMMMMMMMMMMMMMMMMMMMM ....\n  .MMMMMMM8 MMM.  ..MM..MMM:. .IMMM . . ..   .$MMMMMMMMMMMMMMMMMMMMMMMMMMMMM8...\n ..MMM......MMM.. ..MM..:MMM. .MMM  ... .. . MMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMM..\n  .MMM$$$$..MMMMMMMMMM...MMM,.?MM:    . ...NMMMMMMMMMM,   ~MMMMMMMMMMMMMMMMMM   \n  .MMMMMMM..MMMMMMMMMM... MMM MMM ........IMMMMMMMMM8.....+MMMMMMMMMMMMMMMM.....\n ..MMM......MMM.  ..MM....IMMZMM............MMMMMMM. ....MMMMMMMMMMMMMMMM8. ....\n...MMM......MMM.....MM.....NMMMO.......... . .MMMD.  ..NMMMMMMMMMMMMMMMM, .. ...\n ..MMM  . ..MMM.  ..MM..... MMM........ .. . ..Z.....,MMMMMMMMMMMMMMMM$  ... ...\n ..           .   ... .  ..    ... .  . ..      . ..MMMMMMMMMMMMMMMMM. .        \n..      ....  .   . . ... .    .. .   . ..  ..    ~MMMMMMMMMMMMMMMM,.  . ... .  \n... ................................................MMMMMMMMMMMMMM. ............\n .        ... ..  . ....... ............... ... . ....MMMMMMMMMM. . . ..........\n      . .... ... .......... . ................. .......ZMMMMMM:.... ............\n ..    .. ....... ...................................... MMMM. .................\n .      . ..  .   . . ..... . ....... ....  ..  . .. ......: .  ..  . .. ... ...\n .        ..  .   . . .. .. . .... .. . ..   .  . .. . . .....   .  . .. . . ...", 1);

	// BOSS Text
	_driver.moveTo(580, 300);
	_driver.drawString("This is the", 6);
	_driver.moveTo(650, 470);
	_driver.drawString("BOSS", 10);
	_driver.moveTo(650, 530);
	_driver.drawString("Project", 6);
}

DisplayService::~DisplayService() {}

void DisplayService::executeMessage(Message* message)  {
	int* params = message->getParams();
    int response[] = {false};
    if (checkScreenRights(message->getTaskId())) {
    	DisplayServiceCommand command = (DisplayServiceCommand)params[0];
        response[0] = true;
    	switch (command) {
    		case SERVICE_SET_COLOR:
    			_driver.setColor(params[1]);
    			break;
    			
    		case SERVICE_MOVE_TO:
    			_driver.moveTo(params[1], params[2]);
    			break;
    			
    		case SERVICE_DRAW_PIXEL:
    			_driver.drawPixel();
    			break;
    			
    		case SERVICE_DRAW_RECT:
    			_driver.drawRect(params[1], params[2]);
    			break;
    			
    		case SERVICE_DRAW_CHAR:
    			_driver.drawChar(params[1], params[2]);
    			break;
    			
    		case SERVICE_DRAW_STRING:
    			_driver.drawString(((const char*)params + 2), params[1]);
    			break;
            case SERVICE_SWITCH_TASK:
                if ((message->getTaskId() == -1) && (params >= 0)) {
                    changeTo(params[1]);
                }
    	}
    } else {
        int* position = _driver.getPosition();
        int pos[] = {position[0], position[1]};
        unsigned int colour = _driver.getColour();
        
//        _driver.setColor(0x0);
//        _driver.moveTo(30, 48);
//        _driver.drawRect(153, 30);
        _driver.setColor(0xFFFFFF);
        _driver.moveTo(30, 60);
        char* infoString = "Task ";
        _driver.drawString(infoString, 2);
        
        _driver.moveTo(90, 60);
        char infoCharArray[] = {(char)(message->getTaskId() + (unsigned int)'0'), '\0'};
        if (infoCharArray[0] > 255) {
            infoCharArray[0] -= 256;
        }
        _driver.drawString(infoCharArray, 2);
        
        infoString = " wants the screen";
        _driver.moveTo(102, 60);
        _driver.drawString(infoString, 2);
        
        _driver.moveTo(pos[0], pos[1]);
        _driver.restoreColour(colour);
    }
    if (message->getTaskId() >= 0) {
        writeResponse(message->getTaskId(), 1, response);
    }
}

bool DisplayService::checkScreenRights(int taskId) {
    bool isCurrentTask = false;
    if (taskId < 0) {
        isCurrentTask = true;
    } else {
        if (_currentTaskId < 0) {
            changeTo(taskId);
            isCurrentTask = true;
        } else if (_currentTaskId == taskId) {
            isCurrentTask = true;
        }
    }
    return isCurrentTask;
}

void DisplayService::changeTo(int taskId) {
    std::memset(FBADDR, 0x0, 1024*768*4);
    _currentTaskId = taskId;
    
    int* position = _driver.getPosition();
    int pos[] = {position[0], position[1]};
    unsigned int colour = _driver.getColour();
    
//    _driver.setColor(0x0);
//    _driver.moveTo(994, 48);
//    _driver.drawRect(5, 30);
    _driver.setColor(0xFFFFFF);
    _driver.moveTo(994, 60);
    char infoCharArray[] = {(char)(taskId + (unsigned int)'0'), '\0'};
    if (infoCharArray[0] > 255) {
        infoCharArray[0] -= 256;
    }
    _driver.drawString(infoCharArray, 2);
    
    _driver.moveTo(pos[0], pos[1]);
    _driver.restoreColour(colour);
	
	// Set active Task to Serial Service
	setActiveTask(_currentTaskId);
}
