#ifndef SHELLSERVICE_H_
#define SHELLSERVICE_H_

#include "Tasks/Services/Service.h"
#include "Service-API/Display/Display.h"
#include "Service-API/Serial/Serial.h"
#include <string>



class ShellService : public Service
{
private:
	
    int _currentLine;
    int _currentColumn;
	virtual void executeMessage(Message* message);
	
	void init();
    void write(int count, char* buffer);
	int read(int count, char* buffer);
	void writeLineStart();
	// actual command parts
	std::string input;
	
public:

	ShellService();
	virtual ~ShellService();

	void executeCommand(std::string command);
	void echo(char ch);
    void newLine();
};

#endif /*SHELLSERVICE_H_*/
