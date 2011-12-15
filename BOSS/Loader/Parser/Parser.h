
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <list>

#include "API/dataTypes.h"

struct Code  {
	int byteCount;
	int address;
	byte* bytes;
};

class Parser {

private:
	int toInt(char hex);

public:
	Parser();
	virtual ~Parser();

	std::list<Code*>* parse(char hex[]);
	void deleteParsedCode(std::list<Code*>* code);
};

#endif /* PARSER_H_ */
