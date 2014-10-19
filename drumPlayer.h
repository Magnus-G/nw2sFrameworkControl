for (int row=1; row<noOfRows; row++) { // vertical, outputs. start with output 0... first row

	int patternStart = 1;

	// will the program run for this column?
	if (randValueRemove > randRemove) {

		// set drumProgram
		int drumProgram = 0;

		// the trigger
		if (drums[drumProgram][row-1][columnToPlay-1] == 1) {
			digitalWrite(digitalOutputs[row-1], HIGH);

			// send base note levels on analog out
			if (digitalRead(digitalInputs[1]) == 1) {
				outputs[row-1]->outputCV(semitones[notes1[noteProgram][noteColumnToPlay] + noteDistances[chord][0] + baseNote]); 
			}

			// send ASRD on analog out
			else if (digitalRead(digitalInputs[1]) == 0) {
				envelope[row-1] = envelopeMax;
				outputs[row-1]->outputCV(envelope[row-1]); 
			}
		}
		
		// the 1 or 0 from the pattern is added to isThisATrigger
		isThisATrigger[row-1] = drums[drumProgram][row-1][columnToPlay-1]; // give isThisATrigger a 1 or 0 depending on hit or not

		if (randValueAdd < randAdd) {
			digitalWrite(digitalOutputs[row-1], HIGH);
			isThisATrigger[row-1] = 1;
		}

		// check if gate should be turned off or kept open
		if (isThisATrigger[row-1] == 1) { // if this is a hit
			if (everyOtherTrigger[row-1] == 1) { // if the indicator variable shows 1
				digitalWrite(digitalOutputs[row-1], LOW);
				digitalWrite(digitalOutputs[row-1], HIGH);
				digitalWrite(digitalOutputs[row-1], LOW);
				everyOtherTrigger[row-1] = 0; // indicator value set to 0 to indicate that the last hit turned gate off... so next one should keep it on and not go through this loop
			}
			else {
				everyOtherTrigger[row-1] = 1; // so that next time there will be a turning off 
			}
		}  
	} // rand subtract
} // rows

lastColumnPlayed = now; // blir 100

columnToPlay++;

if (columnToPlay > (noOfColumns)) {
	columnToPlay = 1;
}
