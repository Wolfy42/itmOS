#ifndef LOADER_H_
#define LOADER_H_

#include <list>
#include <string.h>

#include "API/dataTypes.h"

#include "Lib/hexOperations.h"

#include "Kernel/RAMManager/RAMManager.h"
#include "Kernel/MMU/mmu.h"
#include "Kernel/Task/Task.h"
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

#include "Loader/TasksHex.h"
#include "Loader/Parser/Parser.h"

class Loader {
	private:
		RAMManager* _ramManager;
		Parser* _parser;
		
		address _memoryStart;
		int _startPageNr;
		int _endPageNr;
		
		bool reserveMemory(std::list<Code*>* code);
		void checkPageNumbers(int address);
		void loadCodeToMemory(std::list<Code*>* code);
		
		void handleDataRecord(Code* dataRecord);
	
	public:
		Loader(RAMManager* ramManager);
		virtual ~Loader();
		
		void loadTaskCode(Task* task, CodeBytes* codeBytes);
		void loadServiceCode(Task* task, CodeBytes* codeBytes, ServiceConfig* config);
};

#endif /* LOADER_H_ */
