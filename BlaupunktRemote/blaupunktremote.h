/*
 * Library to emulate the Blaupunkt Remote RC10
 * Author: Vimal Krishna
 */

#ifndef blaupunktremote_h
#define blaupunktremote_h

#include "Arduino.h"

class BlaupunktRemote
{
	public:
		BlaupunktRemote(char);
		void volumeUp();
		void volumeDown();
		void mute();
		// define the rest of them
	private:
		unsigned char remotePin;
		void pulse(int);
};

#endif
