int noteProgram = analogReadFunction(1, 7); // AnalogIn, ShiftRegister

int noteNumber1 = (notes1[noteProgram][noteToPlay]); // blir en siffra från arrayen
int noteNumber2 = (notes1[noteProgram][noteToPlay] + noteDistances[0]); // blir en siffra från arrayen
int noteNumber3 = (notes1[noteProgram][noteToPlay] + noteDistances[1]); // blir en siffra från arrayen

int noteThatGoesOut1 = semitones[noteNumber1]; // blir cv-valuet från array
int noteThatGoesOut2 = semitones[noteNumber2]; // blir cv-valuet från array
int noteThatGoesOut3 = semitones[noteNumber3]; // blir cv-valuet från array

outputs[0]->outputCV(noteThatGoesOut1);
outputs[1]->outputCV(noteThatGoesOut2);
outputs[2]->outputCV(noteThatGoesOut3);   

noteToPlay++;

if (noteToPlay >= noteSequenceLength) {
	noteToPlay = 0;
}

if ((notes1[noteProgram][noteToPlay] != 66) && playThisNote) {
	digitalWrite(digitalOutputs[15], HIGH);
	digitalWrite(digitalOutputs[15], LOW);	
}