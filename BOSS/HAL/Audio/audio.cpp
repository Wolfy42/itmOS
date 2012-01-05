/*
 * audio.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: stefan
 */
#include "HAL/Audio/audio.h"

Audio::Audio() {
	//	init McBSP2
	_mcbsp2 = new McBSP2();
	_mcbsp2->init_mcbsp2();

	// init TPS65850
	_tps = new TPS65950();
	_tps->init_tps65950();
}

Audio::~Audio() {
	delete _mcbsp2;
	delete _tps;
}

void Audio::playSample() {



}

