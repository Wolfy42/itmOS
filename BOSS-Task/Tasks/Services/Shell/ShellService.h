#ifndef SHELLSERVICE_H_
#define SHELLSERVICE_H_

#include "Tasks/Services/Service.h"
#include <string>



enum ShellCommand {
	NEXT_LETTER
};

class ShellService : public Service
{
private:
	
	virtual void executeMessage(Message* message);
	
	void init();
    void write(int count, char* buffer);
	int read(int count, char* buffer);
	
	// actual command parts
	std::string input;
	
public:

	ShellService();
	virtual ~ShellService();

	void executeCommand(std::string command);
	void echo(std::string echo);
};

#endif /*SHELLSERVICE_H_*/
