
#include "Parser.h"

Parser::Parser()  {}

Parser::~Parser()  {}

std::list<Code*>* Parser::parse(char hex[])  {

	std::list<Code*>* codeLines = new std::list<Code*>;
	int i = 0;
	int recType;
	while (hex[i] != '\0') {
		Code* c = new Code();

		// start code
		i++;

		// byte count
		c->byteCount = 0;
		c->byteCount = toInt(hex[i]);
		i++;
		c->byteCount *= 16;
		c->byteCount += toInt(hex[i]);
		i++;

		// address
		c->address = 0;
		c->address = toInt(hex[i]);
		c->addressHex[0] = hex[i];
		i++;
		c->address *= 16;
		c->address += toInt(hex[i]);
		c->addressHex[1] = hex[i];
		i++;
		c->address *= 16;
		c->address += toInt(hex[i]);
		c->addressHex[2] = hex[i];
		i++;
		c->address *= 16;
		c->address += toInt(hex[i]);
		c->addressHex[3] = hex[i];
		i++;

		// record type
		recType = 0;
		recType = toInt(hex[i]);
		i++;
		recType *= 16;
		recType += toInt(hex[i]);
		c->recordType = recType;
		i++;

		if (recType != 0)  {
			if (recType == RECTYPE_EOF)  {
				// 1 == Last line -> Parsing finished
				return codeLines;
			}  else  {
				printf("Something bad happened! (Intel Hex-RecordType %i unknown", recType);
				return new std::list<Code*>;
			}
		}

		c->bytes = new byte[c->byteCount];
		for (int j=0; j<c->byteCount; j++)  {
			c->bytes[j] = 0;
			c->bytes[j] = toInt(hex[i]);
			i++;
			c->bytes[j] *= 16;
			c->bytes[j] += toInt(hex[i]);
			i++;
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

int Parser::toInt(char hex)  {
	if (hex == '0')  {
		return 0;
	}  else if (hex == '1')  {
		return 1;
	}  else if (hex == '2')  {
		return 2;
	}  else if (hex == '3')  {
		return 3;
	}  else if (hex == '4')  {
		return 4;
	}  else if (hex == '5')  {
		return 5;
	}  else if (hex == '6')  {
		return 6;
	}  else if (hex == '7')  {
		return 7;
	}  else if (hex == '8')  {
		return 8;
	}  else if (hex == '9')  {
		return 9;
	}  else if (hex == 'A')  {
		return 10;
	}  else if (hex == 'B')  {
		return 11;
	}  else if (hex == 'C')  {
		return 12;
	}  else if (hex == 'D')  {
		return 13;
	}  else if (hex == 'E')  {
		return 14;
	}  else if (hex == 'F')  {
		return 15;
	}
	return 0;
}
