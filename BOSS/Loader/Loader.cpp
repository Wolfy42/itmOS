
#include "Loader.h"

Loader::Loader(RAMManager* mmu) : _ramManager(mmu) {
	_parser = new Parser();
	
	// Set some extreme values
	_startPageNr = 255;
	_endPageNr = 0;
}

Loader::~Loader()  {}

bool Loader::reserveMemory() {
	std::list<Code*>::const_iterator iterator;
	
	for (iterator = _code->begin(); iterator != _code->end(); iterator++) {
		Code* codeLine = *iterator;
		
		// Only check the address record
		if (codeLine->recordType == RECTYPE_DATA) {
			// The first hex of the address record defines the page number
			// 		1ABC -> Page 1
			//		4000 -> Page 4
			checkPageNumbers(codeLine->addressHex[0]);
		}
	}

	printf("%c\n", _startPageNr);
	printf("%c\n", _endPageNr);
	
	// Check if pageNr-Logic fails
	if (_startPageNr <= _endPageNr) {
		// Reserve the needed pages and return true		
		int pageCount = _endPageNr - _startPageNr + 1;
		_memoryStart = _ramManager->findFreeMemory(pageCount, true, true);
		return true;
	} else {
		return false; 
	}
}

void Loader::checkPageNumbers(char page) {
	if (page < _startPageNr) {
		_startPageNr = page;
	}
	
	if (page > _endPageNr) {
		_endPageNr = page;
	}
}

void Loader::loadTask(char hex[]) {
	_code = _parser->parse(hex); 
	
	if (reserveMemory()) {
		// Load to reserved memory
	}
}
