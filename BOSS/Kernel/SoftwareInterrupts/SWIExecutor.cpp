
#include "SWIExecutor.h"

SWIExecutor::SWIExecutor(Kernel* kernel) {
	_kernel = kernel;
}
SWIExecutor::~SWIExecutor() {}

void SWIExecutor::executeSWI(int swiNumber, int* parameters)  {

    switch (swiNumber) {
    	case WRITE:
    		//Message* message = new Message(parameters);

         case EXIT:
        	//endTask(parameters[0]);
            break;
        case KILL:
            break;
        case EXEC:
            break;
        case FORK:
            break;
        case YIELD:
            break;
        case SERVICE_CALL:
        	//_kernel->callService(parameters);
            break;
        case SERVICE_RESPONSE:
            break;
        default:
            break;
    }
}
