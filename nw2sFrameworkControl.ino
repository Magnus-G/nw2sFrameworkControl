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

int clockState = false;
int trigIn = false;

void loop() { 

	if (digitalRead(digitalInputs[5]) == 1) {
		if (clockState == false) {
			clockState = true;
			trigIn = true;
		}
	}

	if (digitalRead(digitalInputs[5]) == 0) {
		if (clockState == true) {
			clockState = false;
		}
	}

	// Master clock
	int now = millis(); 

	////////////////////////////////////////////////////////
	//
	//    ANALOG IN POTS (AnalogIn, ShiftRegister) 
	//
	////////////////////////////////////////////////////////

	// Start out by setting the clockState to false in init() 
	// Every loop() check digitalRead(clkIn) 
	// If clkIn true AND clockState is false, then that's the rising edge. 
	  
	//  - On the rising edge set clockState to true 
	//  - On the rising edge do whatever you need to do on a clock cycle 

	// If clkIn is true and clockState is true, then it's not a rising edge or a falling edge so do nothing. 
	// If clkIn is false and clockState is true, then it's a falling edge 
	//  - On the falling edge reset clockState to false 

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

	int noteProgram = analogReadFunction(1, 9); // select note program

	int chord = analogReadFunction(3, 9); // chord structure, distances between three notes

	int baseNote = analogReadFunction(5, 7); // send in cv to set base note (transposing first note)

	int noteIn = analogReadFunction(11, 7);	 // if digital 8 is on then external control of play order

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


			// int envelope[noOfRows] = {0,0,0,0,0,0,0,0,0,0,0};
			// int envelopeMax = 2560;
			// int envelopeIncrementSteps = 80;
			// int envelopeIncrementCurrentOne = 1;

			// Serial.print("envelopeDecay: ");
			// Serial.println(envelopeDecay);

			// Serial.print("envelopeZeroDecay: ");
			// Serial.println(envelopeZeroDecay);

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
