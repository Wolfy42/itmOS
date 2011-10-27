#ifndef SERVICE_H_
#define SERVICE_H_

#include "../API/dataTypes.h"

class Service {
	protected:
		virtual void start() = 0;
		byte* readCommand(int commandId); // Blocking until a command is available
		void writeResponse(byte command[]);
	public:
		Service();
		virtual ~Service();
		
		bool run();
		virtual bool stop() = 0;
		bool restart();
	
};

#endif /*SERVICE_H_*/
