#ifndef SERVICE_H_
#define SERVICE_H_

#include "API/dataTypes.h"

class Service {
	protected:
		virtual void start() = 0;
		void writeResponse(byte command[]);
	public:
		Service();
		virtual ~Service();
        
		virtual int getServiceId() = 0;
        virtual void execute(int params[]) = 0;
		
		bool run();
		virtual bool stop() = 0;
		bool restart();
	
};

#endif /*SERVICE_H_*/
