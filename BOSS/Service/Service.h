#ifndef SERVICE_H_
#define SERVICE_H_

#include "../API/dataTypes.h"

class Service {
	protected:
        void registerService(int id);
		virtual void start() = 0;
		void writeResponse(byte command[]);
	public:
		Service();
		virtual ~Service();
        
        virtual void command(int params[]) = 0;
		
		bool run();
		virtual bool stop() = 0;
		bool restart();
	
};

#endif /*SERVICE_H_*/
