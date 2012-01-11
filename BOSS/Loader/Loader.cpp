
#include "Loader.h"

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
			checkPageNumbers(codeLine->address);
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

void Loader::checkPageNumbers(int address) {
	int page = address / 4096;
	
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
	address currentAddress = (address)((int)_memoryStart + addressOffset - TASK_MEMORY_START);
	
	// Copy data to memory
	memcpy((int*)currentAddress, data, byteCount);
}

void Loader::loadTaskCode(Task* task, CodeBytes* codeBytes) {
	loadServiceCode(task, codeBytes, NULL);
}

void Loader::loadServiceCode(Task* task, CodeBytes* codeBytes, ServiceConfig* config) {
	std::list<Code*>* code = _parser->parse(codeBytes);
	
	if (reserveMemory(code)) {
		// Load code to reserved memory
		loadCodeToMemory(code);
		
		// Create new Task
		task->codeLocation = _memoryStart;
		task->pageCount = _endPageNr - _startPageNr + 1;
		
		if (config != NULL) {
			task->taskRegisters = config->getRegistersForMmuMapping();
		}
	}
	
	_parser->deleteParsedCode(code);
}
