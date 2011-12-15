
#include "Loader.h"

Loader::Loader(MMU* mmu) : _mmu(mmu)  {
	//_mmu->findFreeMemory(10, true, true);
	_startPageNr = 127;
	_endPageNr = 0;
}

Loader::~Loader()  {}

void Loader::determineMemory(char hex[]) {
	int i = 0;
	while (hex[i] != '\0') {
		if (hex[i] == ':') {
			checkPageNumbers(hex[i+3]);
		}
		i++;
	}

	// Ignore Last Row

	printf("%c\n", _startPageNr);
	printf("%c\n", _endPageNr);
}

void Loader::checkPageNumbers(char page) {
	if (page < _startPageNr) {
		_startPageNr = page;
	}
	
	if (page > _endPageNr) {
		_endPageNr = page;
	}
}

std::list<Code*>* Loader::parse(char hex[])  {

	std::list<Code*>* codeLines = new std::list<Code*>;
	int i = 0;
	while (hex[i] != '\0') {
		Code* c = new Code();
		codeLines->push_back(c);

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
		c->addr = 0;
		c->addr = toInt(hex[i]);
		i++;
		c->addr *= 16;
		c->addr += toInt(hex[i]);
		i++;
		c->addr *= 16;
		c->addr += toInt(hex[i]);
		i++;
		c->addr *= 16;
		c->addr += toInt(hex[i]);
		i++;

		// record type
		c->recType = 0;
		c->recType = toInt(hex[i]);
		i++;
		c->recType *= 16;
		c->recType += toInt(hex[i]);
		i++;

		if (c->recType != 0)  {
			if (c->recType == 1)  {
				return codeLines;
			}  else  {
				printf("Something bad happened! (Intel Hex-RecordType %i unknown", c->recType);
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

	}
	return codeLines;
}

int Loader::toInt(char hex)  {
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
