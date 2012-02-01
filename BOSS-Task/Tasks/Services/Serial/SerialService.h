#ifndef SERIALSERVICE_H_
#define SERIALSERVICE_H_

#include "Tasks/Services/Service.h"

class SerialService : public Service {
private:
	int _activeTask;
	
	virtual void executeMessage(Message* message);
	
	void init();
    void write(int count, char* buffer);
	int read(int count, char* buffer);
	
	
	
public:

	SerialService();
	virtual ~SerialService();
	virtual void run();

};

#endif /*SERIALSERVICE_H_*/
