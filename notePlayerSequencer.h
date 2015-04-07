int noteProgram = analogReadFunction(2, 7); // select note program, scale <<<
int chord = analogReadFunction(4, 8); // chord structure, distances between three notes
int baseNote = analogReadFunction(6, 8); // send in cv to set base note (transposing first note)

int note1 = analogReadFunction(1, 6);
int note2 = analogReadFunction(3, 6);
int note3 = analogReadFunction(5, 6);
int note4 = analogReadFunction(7, 6);
int note5 = analogReadFunction(9, 6);
int note6 = analogReadFunction(11, 6);
int note7 = analogReadFunction(10, 6);
int note8 = analogReadFunction(8, 6);

int sequencerNotes[8] = {note1, note2, note3, note4, note5, note6, note7, note8};

if (digitalRead(digitalInputs[1]) == 1) {
	if (sequencerClockState1 == false) {
		sequencerClockState1 = true;
		sequencerTrigIn1 = true;
	}
}


if (digitalRead(digitalInputs[1]) == 0) {
	if (sequencerClockState1 == true) {
		sequencerClockState1 = false;
	}
}

if (sequencerTrigIn1 == true) {

	for(int i = 0; i<4; i++) {
		sequencerNoteDistance = noteDistances[chord][i];
		noteNumber[i] = (notes1[noteProgram][sequencerNotes[noteColumnToPlaySequencer] + sequencerNoteDistance] + baseNote); // blir en siffra från notes-arrayen
	}

	for(int i=0; i<4; i++) {
		noteThatGoesOut[i] = semitones[noteNumber[i]]; // blir cv-valuet från array
	}

	outputs[0]->outputCV(noteThatGoesOut[0]); 
	sequencerTrigIn1 = false;

	noteColumnToPlaySequencer++;

	if (noteColumnToPlaySequencer >= noteSequenceLengthSequencer) {
		noteColumnToPlaySequencer = 0;
	}

	stepsSequencer++;
}

////////

if (digitalRead(digitalInputs[2]) == 1) {
	if (sequencerClockState2 == false) {
		sequencerClockState2 = true;
		sequencerTrigIn2 = true;
	}
}

if (digitalRead(digitalInputs[2]) == 0) {
	if (sequencerClockState2 == true) {
		sequencerClockState2 = false;
	}
}

if (sequencerTrigIn2 == true) {
	outputs[1]->outputCV(noteThatGoesOut[0]); 
	sequencerTrigIn2 = false;
}

