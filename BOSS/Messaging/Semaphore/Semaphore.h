
#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

class Semaphore {
public:
	Semaphore();
	virtual ~Semaphore();

	void P();
	void V();
};

#endif /* SEMAPHORE_H_ */
