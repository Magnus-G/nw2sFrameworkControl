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
	int delayTimeConstrained = constrain(delayTime, 0, 4095); 
	int timerTestValue = delayTimeConstrained + lastColumnPlayed; 

	if (now > timerTestValue) {
		#include "notePlayer.h";
		#include "drumPlayer.h"
	}
}

int analogReadFunction(int x, int y) {
	int settingFlipped = ::analogRead(inputs[x]); // Around 2011 - 0
	int setting = 2020 - settingFlipped; // 0 - 2011
	int settingConstrained = constrain(setting, 0, 2047);  // 0 - 2047
	int settingScaled = settingConstrained >> y; // 1 - 16
	int result = constrain(settingScaled, 0, 15); // force it to be between 0 and 15	
	return result;
}