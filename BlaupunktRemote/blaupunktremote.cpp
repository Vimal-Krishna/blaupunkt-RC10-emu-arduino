/*
 * Library to emulate the Blaupunkt Remote RC10
 * Author: Vimal Krishna
 */

#include "Arduino.h"
#include "blaupunktremote.h"

#define ENDSIGNAL 660

int pulseTime[12] = 
	{
		2600, // 0.  volume up
		3200, // 1.  volume dowm
		3800, // 2.  up button
		4400, // 3.  down button
		5000, // 4.  mute
		5600, // 5.  right button
		6200, // 6.  left button
		6800, // 7.  SRC
		7400, // 8.  OK   --- ??
		8000, // 9.  SRC+ --- ??
		2000, // 10. .    --- ?? 
		 660  // 11. end signal
	};

BlaupunktRemote::BlaupunktRemote(char pin)
{
	remotePin = pin;
	pinMode(remotePin, OUTPUT);
	digitalWrite(remotePin, HIGH);
}

void BlaupunktRemote::volumeUp()
{
	pulse(pulseTime[0]);
}

void BlaupunktRemote::volumeDown()
{
	pulse(pulseTime[1]);
}

void BlaupunktRemote::mute()
{
	pulse(pulseTime[4]);
}

void BlaupunktRemote::pulse(int length)
{
  // pulse of given length
  digitalWrite(remotePin, LOW);
  delayMicroseconds(length);
  digitalWrite(remotePin, HIGH);
  delayMicroseconds(length);

  // pulse to end the signal
  digitalWrite(remotePin, LOW);
  delayMicroseconds(ENDSIGNAL);
  digitalWrite(remotePin, HIGH);
  delayMicroseconds(ENDSIGNAL);
}
