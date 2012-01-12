
#include "Parser.h"

Parser::Parser()  {}

Parser::~Parser()  {}

std::list<Code*>* Parser::parse(CodeBytes* codeBytes)  {

	std::list<Code*>* codeLines = new std::list<Code*>;
	int i = 0;
	int addressOffset = 0;
	int recType;
	int byteCount;
	char* codeByte0 = codeBytes->byte0;
	char* codeByte1 = codeBytes->byte1;
	char* codeByte2 = codeBytes->byte2;
	char* codeByte3 = codeBytes->byte3;
	while (codeByte0[i] != '\0') {
		Code* c = new Code();

		// start code
		i++;

		// byte count
		c->byteCount = 0;
		c->byteCount = hexToInt(codeByte0[i]);
		i++;
		c->byteCount *= 16;
		c->byteCount += hexToInt(codeByte0[i]);
		c->byteCount *= 4; //4 files with bytes
		i++;

		// address
		c->address = 0;
		c->address += hexToInt(codeByte0[i]);
		i++;
		c->address *= 16;
		c->address += hexToInt(codeByte0[i]);
		i++;
		c->address *= 16;
		c->address += hexToInt(codeByte0[i]);
		i++;
		c->address *= 16;
		c->address += hexToInt(codeByte0[i]);
		i++;
		c->address += addressOffset;

		// record type
		recType = 0;
		recType = hexToInt(codeByte0[i]);
		i++;
		recType *= 16;
		recType += hexToInt(codeByte0[i]);
		c->recordType = recType;
		i++;

		if (recType != RECTYPE_DATA)  {
			byteCount = c->byteCount /= 4;
			delete c;

			if (recType == RECTYPE_EOF)  {
				// 1 == Last line -> Parsing finished
				return codeLines;
			}  else if (recType == RECTYPE_EXTENDED_LINEAR_ADDRESS)  {
				addressOffset = 0;
				for (int j = 0; j < byteCount; j++)  {
					addressOffset = hexToInt(codeByte0[i]) * 16;
					i++;
					addressOffset += hexToInt(codeByte0[i]);
					i++;
				}
				addressOffset *= 0x10000;
			}  else  {
//				printf("Something bad happened! (Intel Hex-RecordType %i unknown", recType);
				return new std::list<Code*>;
			}
		}

		if (c->recordType == RECTYPE_DATA)  {

			c->bytes = new byte[c->byteCount];
			for (int j = 0; j < c->byteCount; j+=4)  {
				c->bytes[j] = hexToInt(codeByte0[i]) * 16;
				c->bytes[j+1] = hexToInt(codeByte1[i]) * 16;
				c->bytes[j+2] = hexToInt(codeByte2[i]) * 16;
				c->bytes[j+3] = hexToInt(codeByte3[i]) * 16;
				i++;
				c->bytes[j] += hexToInt(codeByte0[i]);
				c->bytes[j+1] += hexToInt(codeByte1[i]);
				c->bytes[j+2] += hexToInt(codeByte2[i]);
				c->bytes[j+3] += hexToInt(codeByte3[i]);
				i++;
			}
			codeLines->push_back(c);
		}

		//checksum
		i++;
		i++;
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
