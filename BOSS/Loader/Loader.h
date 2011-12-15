#ifndef LOADER_H_
#define LOADER_H_

#include <list>

#include "API/dataTypes.h"
#include "Kernel/MMU/mmu.h"
#include "Loader/TasksHex.h"

struct Code  {
	int byteCount;
	int addr;
	int recType;
	byte* bytes;
};

class Loader {
	private:
		MMU* _mmu;
		void determineMemory(char hex[]);
		
		char _startPageNr;
		char _endPageNr;
		
		void checkPageNumbers(char page);
		int toInt(char hex);
	
	public:
		Loader(MMU* mmu);
		virtual ~Loader();
	
		std::list<Code*>* parse(char hex[]);
};

#endif /* LOADER_H_ */
