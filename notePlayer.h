int setNoteProgramFlipped = ::analogRead(DUE_IN_A01); // Around 2011 - 0
int setNoteProgram = 2020 - setNoteProgramFlipped; // 0 - 2011
int setNoteProgramConstrained = constrain(setNoteProgram, 0, 2047);  // 0 - 2047
int noteProgramScaled = setNoteProgramConstrained >> 7; // 1 - 16
int noteProgram = constrain(noteProgramScaled, 0, 15); // force it to be between 0 and 15

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

	// // Skip one place in sequence?
	int randValueNotePlace = random(0, 500);
	int setRandValueNotePlaceInputFlipped = ::analogRead(DUE_IN_A11);
	int setRandValueNotePlaceInput = 2020 - setRandValueNotePlaceInputFlipped;
	int setRandValueNotePlaceInputConstrained = constrain(setRandValueNotePlaceInput, 0, 2047);
	int setRandValueNotePlaceInputScaled = setRandValueNotePlaceInputConstrained >> 2;
	int randValueNotePlaceInput = constrain(setRandValueNotePlaceInputScaled, 0, 500);

	Serial.println(randValueNotePlaceInput);
	Serial.println(randValueNotePlace);

	// // Skip one place in sequence?
	// int randValueNotePlace = random(0, 500);
	// int randValueNotePlaceInputFlipped = ::analogRead(DUE_IN_A11);
	// int randValueNoteInputPlace = 500 - (constrain(randValueNotePlaceInputFlipped, 0, 500));

	if (randValueNotePlace < randValueNotePlaceInput) {
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