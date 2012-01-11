#include "SWIHandler.h"



SWIHandler::SWIHandler(SystemCallExec* sysCallExec) {

	_sysCallExec = sysCallExec;
}

SWIHandler::~SWIHandler() {}

bool SWIHandler::handle(int swiNumber, int params[])  {

    return _sysCallExec->execute(swiNumber, params);
}
