#ifndef SERIALSERVICE_H_
#define SERIALSERVICE_H_

#include "Tasks/Services/Service.h"


enum SerialCommand {
	SERIAL_WRITE,
	SERIAL_READ
};

class SerialService : public Service
{
private:
	
	virtual void executeMessage(Message* message);
	
	void init();
    void write(int count, char* buffer);
	int read(int count, int* buffer);
	
	
	
public:

	SerialService();
	virtual ~SerialService();
	void run();

};

#endif /*SERIALSERVICE_H_*/
