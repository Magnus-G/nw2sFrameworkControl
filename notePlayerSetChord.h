int noteProgram = analogReadFunction(7, 7); // select scale
int note1 = analogReadFunction(1, 6); // set a note
int note2 = analogReadFunction(3, 6);
int note3 = analogReadFunction(5, 6);

int notes[3] = {note1, note2, note3};

#include "arpCheck1.h";
#include "arpCheck2.h";
#include "arpCheck3.h";

for(int i=0; i<3; i++) {
	noteNumber[i] = notes1[noteProgram][notes[i] + arpAddition[i]]; // blir en siffra från notes-arrayen
	noteThatGoesOut[i] = semitones[noteNumber[i]]; // blir cv-valuet från array
	outputs[i+notePlayerChordOffset]->outputCV(noteThatGoesOut[i]); 
}

