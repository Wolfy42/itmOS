#include "Terminal.h"

Terminal::Terminal()
{
}

Terminal::~Terminal()
{
}

void Terminal::echo() {
	
}

void Terminal::ts() {
	
}


MessageQueue* Terminal::getQueue()  {
	return *(MessageQueue**)0x820F0000;
}

void Terminal::executeMessage(Message* message)  {


}
