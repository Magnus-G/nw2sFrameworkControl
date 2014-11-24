if ((noteTriggerIn == true) || (arpTriggerIn == true) || (incomingNoteOn == 1)) {

	int noteNumber[4]; // The four output notes

	// if Arp is on
	if (arpOn) {
		currentArpStep = noteDistances[chord][arpStep];
	}

	//////////////////////////////////////////////////////


	// CHORDS THAT ARE CONSIDERING THE SCALE
	
	// Arp	
	if (arpOn) {
		for(int i=0; i<4; i++) {
			int noteDistance = noteDistances[chord][i];
			noteNumber[i] = (notes1[noteProgram][noteIn + noteDistance] + baseNote + currentArpStep); // blir en siffra från notes-arrayen
		}
	}

	// Just note step. No arp. Incoming note
	else if (incomingNoteOn) {
		for(int i=0; i<4; i++) {
			int noteDistance = noteDistances[chord][i];
			noteNumber[i] = (notes1[noteProgram][noteIn + noteDistance] + baseNote); // blir en siffra från notes-arrayen
		}
	}

	// BACKUP FOR CREATING CHORDS THAT ARE DEAD RECONING, NOT CONSIDERING THE SCALE

	// if (digitalRead(digitalInputs[4]) == 1) {
	// 	for(int i=0; i<4; i++) {
	// 		noteNumber[i] = (notes1[noteProgram][noteIn] + noteDistances[chord][i] + baseNote + currentArpStep); // blir en siffra från notes-arrayen
	// 	}
	// }

	// else {
	// 	for(int i=0; i<4; i++) {
	// 		noteNumber[i] = (notes1[noteProgram][noteIn] + noteDistances[chord][i] + baseNote); // blir en siffra från notes-arrayen
	// 	}
	// }
	

	for(int i=0; i<4; i++) {
		noteThatGoesOut[i] = semitones[noteNumber[i]]; // blir cv-valuet från array
	}

	//////////////////////////////////////////////////////

	if (pauseNumberOfSteps == 0) {

		// ASR Active
		if (asrActive) {

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
	}

	asr++;
	if (asr == asrLength) { 
		asr = 0;
	}

	//////////////////////////////////////////////////////

	noteColumnToPlay++;

	// Serial.println(noteColumnToPlay);


	if (noteColumnToPlay >= noteSequenceLength) {
		noteColumnToPlay = 0;
	}

	// if ((notes1[noteProgram][noteColumnToPlay] != 66) && playThisNote) {
	// 	digitalWrite(digitalOutputs[11], HIGH);
	// 	digitalWrite(digitalOutputs[11], LOW);	
	// }


	if (arpType == 0) { // Rising
		arpStep++;
	}

	if (arpType == 1) { // Falling
		arpStep--;
	}

	// Reset all note related input triggers
	noteTriggerIn = false;
	arpTriggerIn = false;
	pauseTriggerIn = false;

	pauseNumberOfSteps--;
	if (pauseNumberOfSteps < 0) {
		pauseNumberOfSteps = 0;
	}
}








