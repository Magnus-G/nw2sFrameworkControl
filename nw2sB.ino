#include <b.h>
#include <EventManager.h>
#include <IO.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <aJSON.h>

#include "nw2sInputsAndOutputs.h";
#include "variables.h";
#include "drumSetup.h";
#include "envelopeSetup.h";
#include "notePlayerSetup.h";
#include "setup.h";

void loop() { 

	////////////////////////////////////////////////////////
	int now = millis(); 
	int delayTime = ::analogRead(DUE_IN_A00);
	int delayTimeConstrained = constrain(delayTime, 0, 4095); 
	int timerTestValue = delayTimeConstrained + lastColumnPlayed; 
	////////////////////////////////////////////////////////

	#include "drumPlayer.h"
	// #include "drumPlayerMath.h"
	// #include "drumPlayerPatterns.h"
	// #include "notePlayer.h";
	#include "notePlayerSequencer.h";
	// #include "envelopeProgram.h";


} // loop

int analogReadFunction(int input, int shift) {
	int settingFlipped = ::analogRead(inputs[input]); // Around 2011 - 0
	int setting = 2020 - settingFlipped; // 0 - 2011
	int settingConstrained = constrain(setting, 0, 2047);  // 0 - 2047
	int settingScaled = settingConstrained >> shift; // 1 - 16
	// int result = constrain(settingScaled, 0, 15); // force it to be between 0 and 15	
	int result = settingScaled; // force it to be between 0 and 15	
	return result;
}

int playNoteTriggerFunction(int output, int asrStep) {

	// Don't send trig if previous note is the same as this one.
	if (digitalRead(digitalInputs[6]) == 1) {
		outputs[output]->outputCV(noteThatGoesOut[asrStep]); 

		if (noteThatGoesOut[asrStep] != noteThatWentOut[asrStep]) {
			digitalWrite(digitalOutputs[output], HIGH);
			delay(1);
			digitalWrite(digitalOutputs[output], LOW);	
		}
		noteThatWentOut[asrStep] = noteThatGoesOut[asrStep];
	}
	// Always send note
	else {
		outputs[output]->outputCV(noteThatGoesOut[asrStep]); 
		digitalWrite(digitalOutputs[output], HIGH);
		delay(1);
		digitalWrite(digitalOutputs[output], LOW);	
	}
}
