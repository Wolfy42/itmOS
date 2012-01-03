#include "hexOperations.h"

int hexToInt(char hex) {
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
