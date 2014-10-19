int noteNumber1;
int noteNumber2;
int noteNumber3;
int noteNumber4;

//////////////////////////////////////////////////////

// Read note from A5 if Digital In 7 is ON
if (digitalRead(digitalInputs[8]) == 1) {
	// for(int i=0;  ) {

	// }
	noteNumber1 = (notes1[noteProgram][noteIn] + noteDistances[chord][0] + baseNote); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteIn] + noteDistances[chord][1] + baseNote); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteIn] + noteDistances[chord][2] + baseNote); // blir en siffra från notes-arrayen
	noteNumber4 = (notes1[noteProgram][noteIn] + noteDistances[chord][3] + baseNote); // blir en siffra från notes-arrayen
}

// Read note from array notes[][] if Digital In 7 is OFF
else {
	noteNumber1 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][0] + baseNote); // blir en siffra från notes-arrayen
	noteNumber2 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][1] + baseNote); // blir en siffra från notes-arrayen
	noteNumber3 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][2] + baseNote); // blir en siffra från notes-arrayen
	noteNumber4 = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][3] + baseNote); // blir en siffra från notes-arrayen
}

noteThatGoesOut[0] = semitones[noteNumber1]; // blir cv-valuet från array
noteThatGoesOut[1] = semitones[noteNumber2]; // blir cv-valuet från array
noteThatGoesOut[2] = semitones[noteNumber3]; // blir cv-valuet från array
noteThatGoesOut[3] = semitones[noteNumber4]; // blir cv-valuet från array

//////////////////////////////////////////////////////

// ASR Active
if (digitalRead(digitalInputs[7]) == 1) {

	int randValueSkipNote = random(0, 512);
	int randomSkipNote = analogReadFunction(7, 2); // AnalogIn, ShiftRegister

	if (randValueSkipNote > randomSkipNote) {
		if (asr == 0) { 
			playNoteTriggerFunction(12, 0);
		}
		if (asr == 1) { 
			playNoteTriggerFunction(13, 1);
		}
		if (asr == 2) { 
			playNoteTriggerFunction(14, 2);
		}
		if (asr == 3) { 
			playNoteTriggerFunction(15, 3);
		}
	}
}

// ASR Inactive
else {
	playNoteTriggerFunction(12, 0);
	playNoteTriggerFunction(13, 1);
	playNoteTriggerFunction(14, 2);
	playNoteTriggerFunction(15, 3);
}

asr++;

if (asr == 4) { 
	asr = 0;
}

//////////////////////////////////////////////////////

noteColumnToPlay++;

if (noteColumnToPlay >= noteSequenceLength) {
	noteColumnToPlay = 0;
}

if ((notes1[noteProgram][noteColumnToPlay] != 66) && playThisNote) {
	digitalWrite(digitalOutputs[11], HIGH);
	digitalWrite(digitalOutputs[11], LOW);	
}
