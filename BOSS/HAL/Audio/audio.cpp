/*
 * audio.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: stefan
 */
#include "HAL/Audio/audio.h"
#define reg32r(b, r) (*(volatile uint32_t *)((b)+(r)))
#define reg32w(b, r, v) (*((volatile uint32_t *)((b)+(r))) = (v))

/* envelope details */
struct env {
	unsigned int target;
	unsigned int time;
};

/* adsr of our note */
env adsr[] = {
	{ MAX, ((unsigned int)(SRATE * 0.05)) },
	{ SUS, ((unsigned int)(SRATE * 0.05)) },
	{ SUS, ((unsigned int)(SRATE * 0.2)) },
	{ 0, ((unsigned int)(SRATE * 0.02)) }
};

// A-G is note (G is lower octave).
// 0-9 duration of *next* note in half-notes
char mary[] =
	"BAGABB4BAA4ABD4DBAGABBBBAABA7G"
	"BAGABB4BAA4ABD4DBAGABBBBAABA7G";

char smoke[] =
	"GH2CGHI4CGH2CH4G";

// wavelengths of various basic notes
int ftable[] = {
        (int)(SRATE / 220.000),  /* a3 */
        (int)(SRATE / 246.942),
        (int)(SRATE / 261.626),  /* c3 */
        (int)(SRATE / 293.665),
        (int)(SRATE / 329.628),
        (int)(SRATE / 349.228),
        (int)(SRATE / 195.998),  /* g2 */
        (int)(SRATE / 233.080),  /* h3 */
        (int)(SRATE / 277.180) 	 /* cis */
};

Audio::Audio() {
	//	init McBSP2
	_mcbsp2 = new McBSP2();
	_mcbsp2->init_mcbsp2();

	McBSP1 mcbsp1;
	mcbsp1.init_mcbsp1();

	// init TPS65850
	_tps = new TPS65950();
	_tps->init_tps65950();
}

Audio::~Audio() {
	delete _mcbsp2;
	delete _tps;
}

void Audio::playSample() {

	// just call this function
	// first parameter: wavelength of the note -> http://www.phy.mtu.edu/~suits/notefreqs.html -> 220 is A3
	// second parameter: channel -> use 3 (both)
	// third parameter: length of the tone
	//playnote(220, 3, 400);

	int i = 0;
	while (i++ < 3) {
		//char *np = mary;
		char *np = smoke;
		char n;
		int len = 256;

		while ( (n = *np++) ) {
			if (n >= '0' && n <= '9') {
					len = (n - '0') * 128;
			} else {
					playnote(ftable[n - 'A'], 3, len);
					len = 256;
			}
		}
	}
}

/* play one note with wavelength wvlen to channels lr (bits [1:0]) for sustain length len */
void Audio::playnote(int wvlen, int lr, int len) {
	int i;
	int ampstart = 0;
	int st = 0;

	for (i = 0; i < 4; i++) {
		int at = adsr[i].target;
		int dur = adsr[i].time;
		int j;

		// scale 'sustain' for note length
		if (i == 2) {
			dur = dur * len >> 8;
		}

		for (j = 0; j < dur; j++) {
				int amp = (at-ampstart) * j / dur + ampstart;
				int v = (st*2 - wvlen) * amp / wvlen;

				// send out 2 samples, left/right
				while ((reg32r(MCBSP2_BASE, MCBSPLP_SPCR2_REG) & MCBSP_XRDY) == 0)
						;
				reg32w(MCBSP2_BASE, MCBSPLP_DXR_REG, lr & 1 ? v : 0);
				while ((reg32r(MCBSP2_BASE, MCBSPLP_SPCR2_REG) & MCBSP_XRDY) == 0)
						;
				reg32w(MCBSP2_BASE, MCBSPLP_DXR_REG, lr & 2 ? v : 0);

				st += 1;
				if (st >= wvlen) {
						st = 0;
				}
		}
		ampstart = at;
	}
}
