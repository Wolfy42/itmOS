
#include "Parser.h"
#include "Lib/hexOperations.h"

Parser::Parser()  {}

Parser::~Parser()  {}

std::list<Code*>* Parser::parse(char hex[])  {

	std::list<Code*>* codeLines = new std::list<Code*>;
	int i = 0;
	int addressOffset = 0;
	int recType;
	while (hex[i] != '\0') {
		Code* c = new Code();

		// start code
		i++;

		// byte count
		c->byteCount = 0;
		c->byteCount = hexToInt(hex[i]);
		i++;
		c->byteCount *= 16;
		c->byteCount += hexToInt(hex[i]);
		i++;

		// address
		c->address = 0;
		c->address += hexToInt(hex[i]);
		c->addressHex[0] = hex[i];
		i++;
		c->address *= 16;
		c->address += hexToInt(hex[i]);
		c->addressHex[1] = hex[i];
		i++;
		c->address *= 16;
		c->address += hexToInt(hex[i]);
		c->addressHex[2] = hex[i];
		i++;
		c->address *= 16;
		c->address += hexToInt(hex[i]);
		c->addressHex[3] = hex[i];
		i++;
		c->address += addressOffset;

		// record type
		recType = 0;
		recType = hexToInt(hex[i]);
		i++;
		recType *= 16;
		recType += hexToInt(hex[i]);
		c->recordType = recType;
		i++;

		if (recType != RECTYPE_DATA)  {
			if (recType == RECTYPE_EOF)  {
				// 1 == Last line -> Parsing finished
				return codeLines;
			}  else if (recType == RECTYPE_EXTENDED_LINEAR_ADDRESS)  {
				//do nothing -> will be handled after reading of offset
			}  else  {
				printf("Something bad happened! (Intel Hex-RecordType %i unknown", recType);
				return new std::list<Code*>;
			}
		}

		c->bytes = new byte[c->byteCount];
		for (int j = 0; j < c->byteCount; j += 4)  { 
			for (int k = 3; k >= 0; k--) {
				int currentByte = j + k;
				if (currentByte < c->byteCount) {
					c->bytes[currentByte] = 0;
					c->bytes[currentByte] = hexToInt(hex[i]);
					i++;
					c->bytes[currentByte] *= 16;
					c->bytes[currentByte] += hexToInt(hex[i]);
					i++;
				}
			}
		}		
		if (c->recordType == RECTYPE_EXTENDED_LINEAR_ADDRESS)  {
			addressOffset = c->bytes[0] * 0x10000;
		}

		//checksum
		i++;
		i++;

		codeLines->push_back(c);
	}
	return codeLines;
}

void Parser::deleteParsedCode(std::list<Code*>* code)  {
	std::list<Code*>::const_iterator iterator;
	for(iterator=code->begin(); iterator!=code->end(); iterator++)  {
		delete (*iterator)->bytes;
		delete *iterator;
	}
	delete code;
}
