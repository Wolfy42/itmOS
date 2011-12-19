
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

void Loader::loadCodeToMemory() {
	std::list<Code*>::const_iterator iterator;
	
	for (iterator = _code->begin(); iterator != _code->end(); iterator++) {
		Code* codeLine = *iterator;
		
		// Only check the data records
		// TODO: Implement all the other record-types!
		if (codeLine->recordType == RECTYPE_DATA) {
			handleDataRecord(codeLine);
		}
	}
}

void Loader::handleDataRecord(Code* dataRecord) {
	int addressOffset = dataRecord->address;
	int byteCount = dataRecord->byteCount;
	byte* data = dataRecord->bytes;
	
	// Start address for this record
	address currentAddress = (address)((int)_memoryStart + addressOffset);
	
	// Copy data to memory
	memcpy((int*)currentAddress, data, byteCount);
}

void Loader::loadCode(char hex[]) {
	_code = _parser->parse(hex); 
	
	if (reserveMemory()) {
		// Load code to reserved memory
		loadCodeToMemory();
	}
	
	// TODO -> remove _code as member -> should be passed as parameter
	_parser->deleteParsedCode(_code);
}
