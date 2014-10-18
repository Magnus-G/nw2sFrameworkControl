int noteNumber1;
int noteNumber2;
int noteNumber3;

//////////////////////////////////////////////////////

// Read note from A5 if Digital In 7 is ON
if (digitalRead(digitalInputs[8]) == 1) {
	noteNumber1 = (notes1[noteProgram][noteIn] + noteDistances[chord][0] + baseNote); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteIn] + noteDistances[chord][1] + baseNote); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteIn] + noteDistances[chord][2] + baseNote); // blir en siffra från notes-arrayen
}

// Read note from array notes[][] if Digital In 7 is OFF
else {
	noteNumber1 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][0] + baseNote); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][1] + baseNote); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][2] + baseNote); // blir en siffra från notes-arrayen
}

noteThatGoesOut[0] = semitones[noteNumber1]; // blir cv-valuet från array
noteThatGoesOut[1] = semitones[noteNumber2]; // blir cv-valuet från array
noteThatGoesOut[2] = semitones[noteNumber3]; // blir cv-valuet från array

//////////////////////////////////////////////////////

// ASR Active
if (digitalRead(digitalInputs[7]) == 1) {

	int randValueSkipNote = random(0, 512);
	int randomSkipNote = analogReadFunction(5, 2); // AnalogIn, ShiftRegister

	if (randValueSkipNote > randomSkipNote) {
		if (asr == 0) { 
			playNoteTriggerFunction(13, 0);
		}
		if (asr == 1) { 
			playNoteTriggerFunction(14, 1);
		}
		if (asr == 2) { 
			playNoteTriggerFunction(15, 2);
		}
	}
}

// ASR Inactive
else {
	playNoteTriggerFunction(13, 0);
	playNoteTriggerFunction(14, 1);
	playNoteTriggerFunction(15, 2);
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
