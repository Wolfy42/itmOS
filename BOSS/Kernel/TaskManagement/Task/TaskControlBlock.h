#ifndef TASKCONTROLBLOCK_H_
#define TASKCONTROLBLOCK_H_

class TaskControlBlock {
public:
	TaskControlBlock();
	virtual ~TaskControlBlock();
	
	// getter/setter
	int getProgramCounter() const { return _programCounter; }
	void setProgramCounter(int programCounter) { _programCounter = programCounter; }

	int getStackPointer() const { return _stackPointer; }
	void setStackPointer(int stackPointer) { _stackPointer = stackPointer; }

private:
	// program Counter
	int _programCounter;
	// stack Pointer
	int _stackPointer;
	
	// register - how much? lulz
	
};

#endif /*TASKCONTROLBLOCK_H_*/
