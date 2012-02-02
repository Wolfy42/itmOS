
#include "AudioService.h"
#include "HAL/Audio/audio.h"

AudioService::AudioService() : Service()  {

	// Audio Test -> "berühr dass, und deine Zahnbürste fährt morgens ins Leere!"
	Audio* audio = new Audio();
	while (1)  {
		audio->playSample();
	}
	//delete audio;
}

AudioService::~AudioService()  {}

void AudioService::executeMessage(Message* message)  {

}
