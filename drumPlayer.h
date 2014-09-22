for (int row=1; row<noOfRows; row++) { // vertical, outputs. start with output 0... first row

	int patternStart = 1;

	// will the program run for this column?
	randValueSubtract = random(0, 500);
	int randAnalogInSubtractFlipped = ::analogRead(DUE_IN_A02);
	int randAnalogInSubtract = 500 - (constrain(randAnalogInSubtractFlipped, 0, 500));
	if (randValueSubtract > randAnalogInSubtract) {

		// set drumProgram
		int drumProgram = 0;

		// the trigger
		if (drums[drumProgram][row-1][columnToPlay-1] == 1) {
			digitalWrite(digitalOutputs[row-1], HIGH);
		}
		
		// the 1 or 0 from the pattern is added to isThisATrigger
		isThisATrigger[row-1] = drums[drumProgram][row-1][columnToPlay-1]; // give isThisATrigger a 1 or 0 depending on hit or not

		// a 1 is added to isThisATrigger anyway... maybe
		randValueAdd = random(0, 5000);
		int randAnalogInAddFlipped = ::analogRead(DUE_IN_A04);
		int randAnalogInAdd = 500 - (constrain(randAnalogInAddFlipped, 0, 500));
		if (randValueAdd < randAnalogInAdd) {
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

if (columnToPlay > 15) {
	columnToPlay = 1;
}
