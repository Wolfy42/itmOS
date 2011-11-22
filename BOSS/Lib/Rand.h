/*
 * Rand.h
 *
 *  Created on: Nov 18, 2011
 *      Author: stefan

  rand() implementation taken directly from:

  'Some portable very-long-periodrandom number generators',
  Computers In Physics, Vol. 8, No.1, Jan/Feb 1994

  A copy of which was obtained at:
    http://www.famaf.unc.edu.ar/~kisbye/mys/cip08117.pdf

*/

#ifndef RAND_H_
#define RAND_H_

static unsigned long x=521288629, y=362436069, z=16163801, c=1, n=1131199209;

void srand_(unsigned int seed);

unsigned long rand_(void);

#endif /* RAND_H_ */
