
#include "Loader.h"
#include "Kernel/MMU/mmu.h"

Loader::Loader(RAMManager* mmu) : _ramManager(mmu) {
	_parser = new Parser();
	
	// Set some extreme values
	_startPageNr = 255;
	_endPageNr = 0;
}

Loader::~Loader()  {}

bool Loader::reserveMemory(std::list<Code*>* code) {
	std::list<Code*>::const_iterator iterator;
	
	for (iterator = code->begin(); iterator != code->end(); iterator++) {
		Code* codeLine = *iterator;
		
		// Only check the address record
		if (codeLine->recordType == RECTYPE_DATA) {
			// The first hex of the address record defines the page number
			// 		1ABC -> Page 1
			//		4000 -> Page 4
			checkPageNumbers(toInt(codeLine->addressHex[0]));
		}
	}
	
	// Check if pageNr-Logic fails
	if (_startPageNr <= _endPageNr) {
		// Reserve the needed pages and return true		
		_memoryStart = _ramManager->findFreeMemory(_endPageNr - _startPageNr + 1, false, true);
		return true;
	} else {
		return false; 
	}
}

void Loader::checkPageNumbers(int page) {
	if (page < _startPageNr) {
		_startPageNr = page;
	}
	
	if (page > _endPageNr) {
		_endPageNr = page;
	}
}

void Loader::loadCodeToMemory(std::list<Code*>* code) {
	std::list<Code*>::const_iterator iterator;
	
	for (iterator = code->begin(); iterator != code->end(); iterator++) {
		Code* codeLine = *iterator;
		
		// Only check the data records
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
	// TODO: 0x1000 entfernen bei refactoring
	address currentAddress = (address)((int)_memoryStart + addressOffset - TASK_MEMORY_START);
	
	// Copy data to memory
	memcpy((int*)currentAddress, data, byteCount);
}

void Loader::loadTaskCode(Task* task, char hex[]) {
	std::list<Code*>* code = _parser->parse(hex); 
	
	if (reserveMemory(code)) {
		// Load code to reserved memory
		loadCodeToMemory(code);
		
		// Create new Task
		task->codeLocation = _memoryStart;
		task->pageCount = _endPageNr - _startPageNr + 1;
	}
	
	_parser->deleteParsedCode(code);
}

void Loader::loadServiceCode(Task* task, char hex[], ServiceConfig* config) {
	std::list<Code*>* code = _parser->parse(hex); 
	
	if (reserveMemory(code)) {
		// Load code to reserved memory
		loadCodeToMemory(code);
		
		// Create new Task
		task->codeLocation = _memoryStart;
		task->pageCount = _endPageNr - _startPageNr + 1;
		task->taskRegisters = config->getRegistersForMmuMapping();
	}
	
	_parser->deleteParsedCode(code);
}

// TODO -> Lib
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
