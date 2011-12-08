#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "Tasks/UserModeTask.h"

class Terminal : public UserModeTask 
{
	
private:

	void echo();
	static void ts();

public:
	Terminal();
	virtual ~Terminal();
	
	virtual MessageQueue* getQueue();
	virtual void executeMessage(Message* message);
};

#endif /*TERMINAL_H_*/
