#include "SWIHandler.h"



SWIHandler::SWIHandler(SystemCallExec* sysCallExec) {

	_sysCallExec = sysCallExec;
}

SWIHandler::~SWIHandler() {}

bool SWIHandler::handle(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7)  {

    return _sysCallExec->execute(swiNumber, para1, para2, para3, para4, para5, para6, para7);
}
