#ifndef LOADER_H_
#define LOADER_H_

#include <stdio.h>
#include <list>
#include <string.h>

#include "API/dataTypes.h"
#include "Kernel/RAMManager/RAMManager.h"
#include "Loader/TasksHex.h"
#include "Loader/Parser/Parser.h"
#include "Kernel/Task/Task.h"

class Loader {
	private:
		RAMManager* _ramManager;
		Parser* _parser;
		std::list<Code*>* _code;
		
		address _memoryStart;
		char _startPageNr;
		char _endPageNr;
		
		bool reserveMemory();
		void checkPageNumbers(char page);
		void loadCodeToMemory();
		
		void handleDataRecord(Code* dataRecord);
	
	public:
		Loader(RAMManager* ramManager);
		virtual ~Loader();
		
		void loadCode(Task* task, char hex[]);
};

#endif /* LOADER_H_ */
