/*
 * rand.cpp
 *
 *  Created on: Nov 18, 2011
 *      Author: stefan
 */

#include "Rand.h"

/* This is not meant to be a good seed, just one that initialises a guaranteed sequence */
void srand_(unsigned int seed) {
        x=521288629;
        y=362436069;
        z=16163801 ^ seed;
        c=1;
        n=1131199209;
}

unsigned long rand_(void) {
        long int s;
        if (y > x+c) { s = y - (x+c); c = 0; }
        else { s=y-(x+c)-18; c=1; }
        x = y;
        y = z;
        return (z=s) + (n-69069*n+1013904243);
}
