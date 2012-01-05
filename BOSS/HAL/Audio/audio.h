/*
 * audio.h
 *
 *  Created on: Jan 5, 2012
 *      Author: stefan
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include "HAL/Audio/OMAP/McBSP2.h"
#include "HAL/Audio/TPS65950/TPS65950.h"

class Audio {
private:
	McBSP2* _mcbsp2;
	TPS65950* _tps;
public:
	Audio();
	virtual ~Audio();

	void playSample();
};

#endif /* AUDIO_H_ */
