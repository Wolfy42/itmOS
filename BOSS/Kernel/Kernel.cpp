
#include "Kernel.h"

Kernel::Kernel() {}
Kernel::~Kernel() {}

void Kernel::write(int* parameters)  {

	Message* message = new Message(parameters);
	MessageQueue* messageQueue = _messageQueues.find(message->getTaskId())->second;

	messageQueue->addMessage(message);
}

//void Kernel::startService(Service* service)  {

	//TODO: refactor: What should the Kernel know about the service?
	//_serviceMapping.insert(std::pair<int, Service*>(service->getServiceId(), service));
//	MMU::getInstance()->prepagePagesFor(service->getServiceId());
//}

//void Kernel::callService(int params[])  {

	//_serviceCalls.push_back(new ServiceCall(params));
//}

//void Kernel::executeServiceCalls()  {

	// iterate over all pending service calls
	//ServiceCall* serviceCall;
	//std::list<ServiceCall*>::iterator it;
	//TODO: iterator broken ?
	//for(it=_serviceCalls.begin(); it != _serviceCalls.end(); ++it)  {
		//serviceCall = *it;
	//	serviceCall = _serviceCalls.front();

	/*	int serviceId = serviceCall->getServiceId();
		address parameterAddress = mmu_parameterAddressFor(serviceId);
		ServiceStatus status = (ServiceStatus)parameterAddress[0];

		if (status == SERVICE_FREE)  {

			//copy parameters to Service
			int* params = serviceCall->getParams();
			int length = serviceCall->getParamsLength();
			parameterAddress[0] = SERVICE_REQ;
			memcpy((int*)&parameterAddress[1], params, length * sizeof(int));
			//TODO: high priority for service

		}  else if (status == SERVICE_RESP)  {

			//TODO: respond to task which was calling
			//TODO: free memory of serviceCall
		}  else  {
			//TODO: if long time not responding -> Restart service
		}
	//}*/
//}
