
#ifndef LOADER_H_
#define LOADER_H_

class Loader {
public:
	Loader();
	virtual ~Loader();

	void parse(char hex[]);
};

#endif /* LOADER_H_ */
