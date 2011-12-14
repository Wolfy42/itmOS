#ifndef SERIALSERVICE_H_
#define SERIALSERVICE_H_

#include "Tasks/Services/Service.h"
#include "Tasks/Services/Serial/SerialConfig.h"


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
	int read(int count, char* buffer);
	
	
public:
	SerialService();
	virtual ~SerialService();


	virtual MessageQueue* getQueue();
	
	
	// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~
	// Service-Config
	static SerialConfig CONFIG;
	
	// Service-Main
	static void main(void);
	// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~

};

#endif /*SERIALSERVICE_H_*/
