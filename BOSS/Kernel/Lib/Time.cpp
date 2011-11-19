/*
 * Time.cpp
 *
 *  Created on: Nov 18, 2011
 *      Author: stefan
 */

#include "Kernel/Lib/Time.h"

int time = 3;

/*
 * this time function is magic!
 *
 * really - don't try to understand this one-liner!
 *
 */
int time_() {
	return (time == 3) ? 7 : 3;
}
