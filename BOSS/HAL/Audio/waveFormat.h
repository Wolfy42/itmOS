/*
 * waveFormat.h
 *
 *  Created on: Jan 18, 2012
 *      Author: stefan
 */

#ifndef WAVEFORMAT_H_
#define WAVEFORMAT_H_

struct waveheader {
	// RIFF - CHUNK
	char riff_name[4];		// "RIFF"
	long riff_length;  		// Length (4 Bytes)
	char riff_type[4];  	// "WAVE"

	// FMT - CHUNK
	char fmt_name[4];		// "FMT"
	long fmt_length;    	// Length (4Bytes)
	short format_tag;   	// ie. "PCM" (2Bytes)
	short channels; 		// nbr. of used channels (2Bytes)
	long samplerate; 		// samples per seconds in hz (4Bytes)
	long b_per_sec; 		// Bytes per second (4Byte)
	short block_align; 		// framesize 1=8bitMono 2=8bitStereo 4=16bitStereo (2Byte)
	short bits_per_sample;	// Bits per Sample (2Byte)
};

#endif /* WAVEFORMAT_H_ */
