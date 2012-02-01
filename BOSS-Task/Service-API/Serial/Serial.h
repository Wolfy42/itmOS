#ifndef SERIAL_H_
#define SERIAL_H_

enum SerialServiceCommand {
    SERIAL_WRITE,
	SERIAL_READ,
    NEXT_CHAR,
    SET_ACTIVE_TASK
};


void nextChar(int receiver, char ch);

void setActiveTask(int activeTask);

#endif /*SERIAL_H_*/
