randValueRemove = random(1, 15);
randValueAdd = random(1, 15);

// input number, bitshift value
int noteProgram = analogReadFunction(1, 7); // select note program, scale <<<
int randRemove = analogReadFunction(2, 7); // a 1 is removed from isThisATrigger ... maybe
int chord = analogReadFunction(3, 8); // chord structure, distances between three notes
int randAdd = analogReadFunction(4, 7); // a 1 is added to isThisATrigger anyway... maybe
int baseNote = analogReadFunction(5, 8); // send in cv to set base note (transposing first note)
int arpType = analogReadFunction(7, 10);
int asrLength = analogReadFunction(8, 9) + 1;
int pauseTime = analogReadFunction(9, 9);
int noteIn = analogReadFunction(11, 6);	 // if digital 8 is on then external control of play order

if ((noteTriggerIn == true) || (arpTriggerIn == true) || (incomingNoteOn == 1)) {

	int noteNumber[4]; // The four output notes

	// if Arp is on
	// if (arpOn) {
	// 	currentArpStep = noteDistances[chord][arpStep];
	// }

	//////////////////////////////////////////////////////


	// CHORDS THAT ARE CONSIDERING THE SCALE
	
	// Arp	
	// if (arpOn) {
	// 	for(int i=0; i<4; i++) {
	// 		int noteDistance = noteDistances[chord][i];
	// 		noteNumber[i] = (notes1[noteProgram][noteIn + noteDistance] + baseNote + currentArpStep); // blir en siffra från notes-arrayen
	// 	}
	// }

	// Just note step. No arp. Incoming note
	// else if (incomingNoteOn) {
		for(int i=0; i<4; i++) {
			int noteDistance = noteDistances[chord][i];
			noteNumber[i] = (notes1[noteProgram][noteIn + noteDistance] + baseNote); // blir en siffra från notes-arrayen
		}
	// }

	for(int i=0; i<4; i++) {
		noteThatGoesOut[i] = semitones[noteNumber[i]]; // blir cv-valuet från array
	}

	//////////////////////////////////////////////////////

	if (pauseNumberOfSteps == 0) {

		// ASR Active
		// if (asrActive) {

		// 	int randValueSkipNote = random(0, 512);
		// 	int randomSkipNote = analogReadFunction(7, 2); // AnalogIn, ShiftRegister

		// 	if (randValueSkipNote > randomSkipNote) {
		// 		if (asr == 0) { 
		// 			playNoteTriggerFunction(12, 0);
		// 		}
		// 		if (asr == 1) { 
		// 			playNoteTriggerFunction(13, 1);
		// 		}
		// 		if (asr == 2) { 
		// 			playNoteTriggerFunction(14, 2);
		// 		}
		// 		if (asr == 3) { 
		// 			playNoteTriggerFunction(15, 3);
		// 		}
		// 	}
		// }

		// ASR Inactive
		// else {
			playNoteTriggerFunction(12, 0);
			playNoteTriggerFunction(13, 1);
			playNoteTriggerFunction(14, 2);
			playNoteTriggerFunction(15, 3);
		// }
	}

	// asr++;
	// if (asr == asrLength) { 
	// 	asr = 0;
	// }

	//////////////////////////////////////////////////////

	noteColumnToPlay++;

	if (noteColumnToPlay >= noteSequenceLength) {
		noteColumnToPlay = 0;
	}

	// if (arpType == 0) { // Rising
	// 	arpStep++;
	// }

	// if (arpType == 1) { // Falling
	// 	arpStep--;
	// }

	// Reset all note related input triggers
	noteTriggerIn = false;
	// arpTriggerIn = false;
	// pauseTriggerIn = false;

	// pauseNumberOfSteps--;
	// if (pauseNumberOfSteps < 0) {
	// 	pauseNumberOfSteps = 0;
	// }
}








