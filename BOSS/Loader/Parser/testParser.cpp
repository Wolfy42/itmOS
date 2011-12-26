#include <stdio.h>
#include <list>

#include "Loader/Parser/Parser.h"
#include "Loader/TasksHex.h"

int _main(int argc, char **argv) {

	Parser p;
	CodeBytes* cb = new CodeBytes;
	cb->byte0 = test_byte_0;
	cb->byte1 = test_byte_1;
	cb->byte2 = test_byte_2;
	cb->byte3 = test_byte_3;

	std::list<Code*>* code = p.parse(cb);

	std::list<Code*>::const_iterator cii;
	for(cii=code->begin(); cii!=code->end(); cii++)  {
		printf("> byteCount: %x, addr: %x\n\t", (*cii)->byteCount, (*cii)->address);
		for (int i=0; i<(*cii)->byteCount; i++)  {
			if (i%4 == 0) {
				printf(" ");
			}
			printf("%x%x", (*cii)->bytes[i]>>4, (*cii)->bytes[i]%16);
		}
		printf("\n");
	}
	printf("deleting....\n");
	p.deleteParsedCode(code);
	return 0;
}
