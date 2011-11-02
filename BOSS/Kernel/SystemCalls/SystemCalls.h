#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_

class SystemCalls
{
public:
	SystemCalls();
	virtual ~SystemCalls();
	
	// let the calling process sleep for ms microseconds
	int sleep(int ms);
};

#endif /*SYSTEMCALLS_H_*/
