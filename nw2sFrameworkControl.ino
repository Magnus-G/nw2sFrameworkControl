#include <b.h>
#include <EventManager.h>
#include <IO.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <aJSON.h>

#include "nw2sInputsAndOutputs.h";
#include "drumSetup.h";
#include "notePlayerSetup.h";
#include "setup.h";

void loop() { 

	// Master clock
	int now = millis(); 
	int delayTime = ::analogRead(DUE_IN_A00);
	int timerTestValue = delayTime + lastColumnPlayed; 

	if (now > timerTestValue) {
		#include "notePlayer.h";
		#include "drumPlayer.h"
	}
}