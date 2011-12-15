#ifndef LOADER_H_
#define LOADER_H_

#include <stdio.h>

#include "Kernel/MMU/mmu.h"
#include "Loader/TasksHex.h"

class Loader {
	private:
		MMU* _mmu;
		void determineMemory(char hex[]);
		
		char _startPageNr;
		char _endPageNr;
		
		void checkPageNumbers(char page);
	
	public:
		Loader(MMU* mmu);
		virtual ~Loader();
};

#endif /* LOADER_H_ */
