if ((noteTriggerIn == true) || (arpTriggerIn == true)) {

	int noteNumber[4];

	int currentArpStep = noteDistances[chord][arpStep];
	Serial.println(currentArpStep);

	//////////////////////////////////////////////////////

	// Read note from A5 if Digital In 7 is ON. i.e. external reading.
	if (digitalRead(digitalInputs[8]) == 1) {
		for(int i=0; i<4; i++) {
			noteNumber[i] = (notes1[noteProgram][noteIn] + noteDistances[chord][i] + baseNote + currentArpStep); // blir en siffra från notes-arrayen
		}
	}

	// Read note from array notes[][] if Digital In 7 is OFF. i.e. auto run through note pattern
	else {
		for(int i=0; i<4; i++) {
			noteNumber[i] = (notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][i] + baseNote + currentArpStep); // blir en siffra från notes-arrayen
		}
	}

	for(int i=0; i<4; i++) {
		noteThatGoesOut[i] = semitones[noteNumber[i]]; // blir cv-valuet från array
	}

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

	noteTriggerIn = false;
	arpTriggerIn = false;
}