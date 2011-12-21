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
#include "Kernel/ServiceManager/Configs/ServiceConfig.h"

class Loader {
	private:
		RAMManager* _ramManager;
		Parser* _parser;
		
		address _memoryStart;
		int _startPageNr;
		int _endPageNr;
		
		bool reserveMemory(std::list<Code*>* code);
		void checkPageNumbers(int page);
		void loadCodeToMemory(std::list<Code*>* code);
		
		void handleDataRecord(Code* dataRecord);
		
		// TODO -> Lib
		int toInt(char hex);
	
	public:
		Loader(RAMManager* ramManager);
		virtual ~Loader();
		
		void loadTaskCode(Task* task, char hex[]);
		void loadServiceCode(Task* task, char hex[], ServiceConfig* config);
};

#endif /* LOADER_H_ */
