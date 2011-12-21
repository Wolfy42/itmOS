
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <list>

#include "API/dataTypes.h"

// RecType defines
#define RECTYPE_DATA 						0x0
#define RECTYPE_EOF 						0x1
#define RECTYPE_EXTENDED_SEGMENT_ADDRESS 	0x2
#define RECTYPE_START_SEGMENT_ADDRESS		0x3
#define RECTYPE_EXTENDED_LINEAR_ADDRESS 	0x4
#define RECTYPE_START_LINEAR_ADDRESS 		0x5

struct Code  {
	int byteCount;
	char addressHex[4];
	int address;
	int recordType;
	byte* bytes;
};

class Parser {
	public:
		Parser();
		virtual ~Parser();
	
		std::list<Code*>* parse(char hex[]);
		void deleteParsedCode(std::list<Code*>* code);
};

#endif /* PARSER_H_ */
