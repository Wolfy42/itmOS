#include "SWIHandler.h"



SWIHandler::SWIHandler(SystemCallExec* sysCallExec) {

	_sysCallExec = sysCallExec;
}

SWIHandler::~SWIHandler() {}

bool SWIHandler::handle(int swiNumber, int params[])  {

    return _sysCallExec->execute(swiNumber, params[0], params[1], params[2], params[3], params[4], params[5], params[6]);
}
