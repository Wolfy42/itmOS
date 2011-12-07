#include "SWIHandler.h"



SWIHandler::SWIHandler(SystemCallExec* sysCallExec) {

	_sysCallExec = sysCallExec;
}

SWIHandler::~SWIHandler() {}

bool SWIHandler::handle(int swiNumber, int* parameters)  {

    return _sysCallExec->execute(swiNumber, parameters);
}
