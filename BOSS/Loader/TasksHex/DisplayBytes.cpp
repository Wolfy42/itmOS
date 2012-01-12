
#include "DisplayBytes.h"

DisplayBytes::DisplayBytes()  {}

CodeBytes* DisplayBytes::getCodeBytes()  {

	CodeBytes* cb = new CodeBytes();

	cb->byte0 = "";
	cb->byte1 = "";
	cb->byte2 = "";
	cb->byte3 = "";

	return cb;
}
