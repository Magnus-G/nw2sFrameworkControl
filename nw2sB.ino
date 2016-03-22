#include <b.h>
#include <EventManager.h>
#include <IO.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <aJSON.h>

#include "nw2sInputsAndOutputs.h";
#include "variables.h";
#include "drumPlayerSetup.h";
#include "envelopeSetup.h";
#include "notePlayerSetup.h";
#include "arpSetup.h";
#include "setup.h";
#include "audioInToAudioOutSetup.h"

void loop() { 

	////////////////////////////////////////////////////////
	int now = millis(); 
	int delayTime = ::analogRead(DUE_IN_A00);
	int delayTimeConstrained = constrain(delayTime, 0, 4095); 
	int timerTestValue = delayTimeConstrained + lastColumnPlayed; 
	////////////////////////////////////////////////////////

	#include "removeHit.h"
	#include "addHit.h"
	
	if (now > timerTestValue) {
		#include "drumPlayer.h"
	}

	int analogOutDelayTime = ::analogRead(DUE_IN_A11);
	int analogOutDelayTimeConstrained = constrain(analogOutDelayTime, 0, 500); 

	// all analog outs get notes on digital out drumshift
	// for(int i=0; i<13; i++) {
	// 	if (now > (analogOutTimers[i] + analogOutDelayTimeConstrained)) {
	// 		outputs[i]->outputCV(0);
	// 	}
	// }

	// #include "drumPlayerMath.h"
	// #include "drumPlayerPatterns.h"
	
	// #include "notePlayer.h";
	// #include "notePlayerSequencer.h";
	#include "notePlayerSetChord.h";
	// #include "envelopeProgram.h";

	#include "audioInToAudioOut.h";

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
