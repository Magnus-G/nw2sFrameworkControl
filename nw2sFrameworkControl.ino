#include <b.h>
#include <EventManager.h>
#include <IO.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <aJSON.h>

#include "nw2sInputsAndOutputs.h";
#include "drumSetup.h";
#include "envelopeSetup.h";
#include "notePlayerSetup.h";
#include "setup.h";

void loop() { 

	if (digitalRead(digitalInputs[4]) == 1) {
		arpOn = 1;
	}

	else {
		arpOn = 0;	
	}

	if (digitalRead(digitalInputs[5]) == 1) {
		noteOn = 1;
	}

	else {
		noteOn = 0;	
	}

	if (digitalRead(digitalInputs[8]) == 1) {
		incomingNoteOn = 1;
	}

	else {
		incomingNoteOn = 0;	
	}

	if (digitalRead(digitalInputs[2]) == 1) {
		asrActive = 1;
	}

	else {
		asrActive = 0;	
	}


	int arpType = analogReadFunction(7, 10);

	int pauseTime = analogReadFunction(9, 9);

	int asrLength = analogReadFunction(8, 9) + 1;

	// Serial.println(asrLength);

	if (digitalRead(digitalInputs[7]) == 1) {
		if (pauseState == false) {
			pauseState = true;
			pauseTriggerIn = true;
			pauseNumberOfSteps = pauseTime;
		}
	}

	if (digitalRead(digitalInputs[7]) == 0) {
		if (pauseState == true) {
			pauseState = false;
		}
	}


	// trig note with input

	if (digitalRead(digitalInputs[5]) == 1) {
		if (clockState == false) {
			clockState = true;
			noteTriggerIn = true;
		}
	}

	if (digitalRead(digitalInputs[5]) == 0) {
		if (clockState == true) {
			clockState = false;
		}
	}

	// Arpeggio

	if (digitalRead(digitalInputs[4]) == 1) {
		if (arpClockState == false) {
			arpClockState = true;
			arpTriggerIn = true;

			if (arpType == 0) { // Rising arp
				if(arpStep > 3) {
					arpStep = 0;
				}
			}

		}
	}

	if (digitalRead(digitalInputs[4]) == 0) {
		if (arpClockState == true) {
			arpClockState = false;
		}
	}

	// Master clock
	int now = millis(); 

	//    ANALOG IN POTS (AnalogIn, ShiftRegister) 
	////////////////////////////////////////////////////////

	int drumProgram = 0;

	int delayTime = ::analogRead(DUE_IN_A00);
	int delayTimeConstrained = constrain(delayTime, 0, 4095); 
	int timerTestValue = delayTimeConstrained + lastColumnPlayed; 

	randValueRemove = random(1, 15);
	int randRemove = analogReadFunction(2, 7); // a 1 is removed from isThisATrigger ... maybe
	
	randValueAdd = random(1, 15);
	int randAdd = analogReadFunction(4, 7); // a 1 is added to isThisATrigger anyway... maybe

	int envelopeDecay = analogReadFunction(6, 6); 
	int envelopeZeroDecay = 16;

	////////////////////////////////////////////////////////

	int noteProgram = analogReadFunction(1, 7); // select note program, scale

	int chord = analogReadFunction(3, 8); // chord structure, distances between three notes

	int baseNote = analogReadFunction(5, 8); // send in cv to set base note (transposing first note)

	int noteIn = analogReadFunction(11, 6);	 // if digital 8 is on then external control of play order

	////////////////////////////////////////////////////////

	if (now > timerTestValue) {
		#include "drumPlayer.h"
	}

	#include "notePlayer.h";

	// each decay increment will be this long
	int envelopeIncrementValue = delayTimeConstrained / envelopeIncrementSteps;

	if (now > (lastColumnPlayed + (envelopeIncrementValue * envelopeIncrementCurrentOne))) {

		// envelopes or levels
		if (digitalRead(digitalInputs[1]) == 0) {

			// decrease the Envelopes
			if(envelopeDecay > envelopeZeroDecay) {
				for (int row=1; row<noOfRows; row++) { 
					int envelopeDecreasePerStep = (envelopeMax / envelopeIncrementSteps) * 2;
					envelope[row-1] -= envelopeDecreasePerStep * (envelopeDecreasePerStep / envelopeDecay); // 2560 div by 80 is 32 
					if (envelope[row-1] < 0) {
						envelope[row-1] = 0;
					}
					outputs[row-1]->outputCV(envelope[row-1]); 
				}
			}

			// if negative decay
			else if(envelopeDecay < envelopeZeroDecay) {
				for (int row=1; row<noOfRows; row++) { 
					int envelopeIncreasePerStep = envelopeMax / envelopeIncrementSteps;
					envelope[row-1] += envelopeIncreasePerStep * (envelopeIncreasePerStep / envelopeDecay+1); // 2560 div by 80 is 32 
					if (envelope[row-1] > envelopeMax) {
						envelope[row-1] = 0;
					}
					outputs[row-1]->outputCV(envelope[row-1]); 
				}	
			}

			envelopeIncrementCurrentOne++;

			if(envelopeIncrementCurrentOne == envelopeIncrementSteps) {
				envelopeIncrementCurrentOne = 1;
			}
		}
	}
} // loop






// Functions //////////////////////////////////////////////////////

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
