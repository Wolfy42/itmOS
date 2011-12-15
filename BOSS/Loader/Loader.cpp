#include <stdio.h>
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

void Loader::parse(char hex[])  {
	determineMemory(hex);
	
	/*int i = 0;
	while (hex[i] != '\0')  {
		i++;
	}*/
}

