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

	////////////////////////////////////////////////////////
	//
	//    ANALOG IN POTS (AnalogIn, ShiftRegister) 
	//
	////////////////////////////////////////////////////////

	int delayTime = ::analogRead(DUE_IN_A00);
	int delayTimeConstrained = constrain(delayTime, 0, 4095); 
	int timerTestValue = delayTimeConstrained + lastColumnPlayed; 

	randValueRemove = random(1, 15);
	int randRemove = analogReadFunction(2, 7); // a 1 is removed from isThisATrigger ... maybe
	
	randValueAdd = random(1, 15);
	int randAdd = analogReadFunction(4, 7); // a 1 is added to isThisATrigger anyway... maybe

	////////////////////////////////////////////////////////

	int noteProgram = analogReadFunction(1, 10); // select note program

	int chord = analogReadFunction(3, 9); // chord structure, distances between three notes

	int baseNote = analogReadFunction(5, 7); // send in cv to set base note (transposing first note)

	int noteIn = analogReadFunction(11, 7);	 // if digital 8 is on then external control of play order

	////////////////////////////////////////////////////////

	if (now > timerTestValue) {
		#include "notePlayer.h";
		#include "drumPlayer.h"
	}
}

// Functions //////////////////////////////////////////////////////

int analogReadFunction(int x, int y) {
	int settingFlipped = ::analogRead(inputs[x]); // Around 2011 - 0
	int setting = 2020 - settingFlipped; // 0 - 2011
	int settingConstrained = constrain(setting, 0, 2047);  // 0 - 2047
	int settingScaled = settingConstrained >> y; // 1 - 16
	int result = constrain(settingScaled, 0, 15); // force it to be between 0 and 15	
	return result;
}

int playNoteTriggerFunction(int x, int y) {

	if (digitalRead(digitalInputs[6]) == 1) {
		outputs[x]->outputCV(noteThatGoesOut[y]); 

		if (noteThatGoesOut[y] != noteThatWentOut[y]) {
			digitalWrite(digitalOutputs[x], HIGH);
			delay(1);
			digitalWrite(digitalOutputs[x], LOW);	
		}
		noteThatWentOut[y] = noteThatGoesOut[y];
	}
	else {
		outputs[x]->outputCV(noteThatGoesOut[y]); 
		digitalWrite(digitalOutputs[x], HIGH);
		delay(1);
		digitalWrite(digitalOutputs[x], LOW);	
	}
}
