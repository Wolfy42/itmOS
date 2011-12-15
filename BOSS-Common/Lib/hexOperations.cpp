#include <ctype.h>
#include <string.h>
#include "hexOperations.h"

// Converts a hexadecimal string to integer
int xtoi(const char* xs, unsigned int* result) {
	size_t szlen = strlen(xs);
 	int i, xv, fact;

 	if (szlen > 0) {
  		// Converting more than 32bit hexadecimal value?
  		if (szlen > 8) {
  			return 2; // exit
  		}

  		// Begin conversion here
  		*result = 0;
 		fact = 1;

  		// Run until no more character to convert
  		for(i = szlen - 1; i >= 0; i--) {
   			if (isxdigit(*(xs + i))) {
    			if (*(xs + i) >= 97) {
     				xv = ( *(xs+i) - 97) + 10;
    			} 
    			else if ( *(xs+i) >= 65) {
     				xv = (*(xs+i) - 65) + 10;
  				} 
  				else {
	     			xv = *(xs + i) - 48;
	    		}
	    		
	    		*result += (xv * fact);
	    		fact *= 16;
	    		
   			} else {
	    		// Conversion was abnormally terminated
	    		// by non hexadecimal digit, hence
	    		// returning only the converted with
	    		// an error value 4 (illegal hex character)
	    		return 4;
	 		}
  		}
	}
 	// Nothing to convert
 	return 1;
}
