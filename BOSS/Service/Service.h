#ifndef SERVICE_H_
#define SERVICE_H_

#include <stdio.h>
#include <string.h>

#include "API/dataTypes.h"

enum ServiceStatus {
	SERVICE_FREE,
	SERVICE_REQ,
	SERVICE_RESP
};

class Service {

	private:
		int* _parameterAddress;

	protected:
		void writeResponse(int params[]);
		virtual void execute(int params[]) = 0;

	public:
		Service();
		virtual ~Service();
		void run();
        
		virtual int getServiceId() = 0;
};

#endif /*SERVICE_H_*/
