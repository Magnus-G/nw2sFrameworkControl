int noteProgramFlipped = ::analogRead(DUE_IN_A01);
int noteProgram = (noOfNotePrograms - (constrain(noteProgramFlipped, 0, noOfNotePrograms))) - 1;
if (noteProgram < 0) { noteProgram = 0; }

Serial.println(noteProgram);

int noteThatGoesOut1 = (notes1[noteProgram][noteToPlay] * tuning);
int noteThatGoesOut2 = (notes1[noteProgram][noteToPlay] + noteDistances[0]) * tuning;
int noteThatGoesOut3 = (notes1[noteProgram][noteToPlay] + noteDistances[1]) * tuning;

if (digitalRead(digitalInputs[1]) == 1) {
	noteThatGoesOut1 = (notes1[noteProgram][noteToPlay] + 2) * tuning;
}

if (digitalRead(digitalInputs[2]) == 1) {
	noteThatGoesOut2 = (notes1[noteProgram][noteToPlay] + noteDistances[0] + 2) * tuning;
}

if (digitalRead(digitalInputs[3]) == 1) {
	noteThatGoesOut3 = (notes1[noteProgram][noteToPlay] + noteDistances[1] + 2) * tuning;
}

// if not an empty note
if (notes1[0][noteToPlay] < 77) {

	// Skip one place in sequence?
	int randValueNotePlace = random(0, 500);
	int randValueNotePlaceInputFlipped = ::analogRead(DUE_IN_A11);
	int randValueNoteInputPlace = 500 - (constrain(randValueNotePlaceInputFlipped, 0, 500));

	if (randValueNotePlace < randValueNoteInputPlace) {
		noteToPlay++;
	}

	// Skip this output?
	int randValueSubtractNote = random(0, 500);
	int randAnalogInSubtractNoteFlipped = ::analogRead(DUE_IN_A03);
	int randAnalogInSubtractNote = 500 - (constrain(randAnalogInSubtractNoteFlipped, 0, 500));
	if (randValueSubtractNote < randAnalogInSubtractNote) {
		playThisNote = 0;
	}
	else {
		playThisNote = 1;	
	}

	outputs[0]->outputCV(noteThatGoesOut1);  
	outputs[1]->outputCV(noteThatGoesOut2);  
	outputs[2]->outputCV(noteThatGoesOut3);  

	if ((notes1[0][noteToPlay] != 0) && playThisNote) {
		digitalWrite(digitalOutputs[15], HIGH);
		digitalWrite(digitalOutputs[15], LOW);	
	}

	noteToPlay++;

	if (noteToPlay >= noteSequenceLength) {
		noteToPlay = 0;
	}
}

// if an empty note
else {
	noteToPlay = 0;
}