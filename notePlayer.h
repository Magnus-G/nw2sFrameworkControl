int noteProgram = analogReadFunction(1, 7); // AnalogIn, ShiftRegister
int chord = analogReadFunction(3, 9); 			// AnalogIn, ShiftRegister
int noteIn = analogReadFunction(5, 7);						// AnalogIn, ShiftRegister

int noteNumber1;
int noteNumber2;
int noteNumber3;

//////////////////////////////////////////////////////

// Read note from A5 if Digital In 7 is ON
if (digitalRead(digitalInputs[7]) == 1) {
	noteNumber1 = (notes1[noteProgram][noteIn] + noteDistances[chord][0]); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteIn] + noteDistances[chord][1]); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteIn] + noteDistances[chord][2]); // blir en siffra från notes-arrayen
}

// Read note from array notes[][] if Digital In 7 is OFF
else {
	noteNumber1 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][0]); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][1]); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][2]); // blir en siffra från notes-arrayen
}

int noteThatGoesOut1 = semitones[noteNumber1]; // blir cv-valuet från array
int noteThatGoesOut2 = semitones[noteNumber2]; // blir cv-valuet från array
int noteThatGoesOut3 = semitones[noteNumber3]; // blir cv-valuet från array

//////////////////////////////////////////////////////

// ASR Active
if (digitalRead(digitalInputs[8]) == 1) {

	int randValueSkipNote = random(0, 512);
	int randomSkipNote = analogReadFunction(5, 2); // AnalogIn, ShiftRegister

	if (randValueSkipNote > randomSkipNote) {
		if (asr == 0) { 
			outputs[13]->outputCV(noteThatGoesOut1); 
			digitalWrite(digitalOutputs[13], HIGH);
			digitalWrite(digitalOutputs[13], LOW);	
		}
		if (asr == 1) { 
			outputs[14]->outputCV(noteThatGoesOut2); 
			digitalWrite(digitalOutputs[14], HIGH);
			digitalWrite(digitalOutputs[14], LOW);	
		}
		if (asr == 2) { 
			outputs[15]->outputCV(noteThatGoesOut3); 
			digitalWrite(digitalOutputs[15], HIGH);
			digitalWrite(digitalOutputs[15], LOW);	
		}
	}
}

// ASR Inactive
else {
	outputs[13]->outputCV(noteThatGoesOut1);
	outputs[14]->outputCV(noteThatGoesOut2);
	outputs[15]->outputCV(noteThatGoesOut3);   
	digitalWrite(digitalOutputs[13], HIGH);
	digitalWrite(digitalOutputs[13], LOW);	
	digitalWrite(digitalOutputs[14], HIGH);
	digitalWrite(digitalOutputs[14], LOW);	
	digitalWrite(digitalOutputs[15], HIGH);
	digitalWrite(digitalOutputs[15], LOW);	
}

asr++;

if (asr == 3) { 
	asr = 0;
}

//////////////////////////////////////////////////////

noteColumnToPlay++;

if (noteColumnToPlay >= noteSequenceLength) {
	noteColumnToPlay = 0;
}

if ((notes1[noteProgram][noteColumnToPlay] != 66) && playThisNote) {
	digitalWrite(digitalOutputs[12], HIGH);
	digitalWrite(digitalOutputs[12], LOW);	
}