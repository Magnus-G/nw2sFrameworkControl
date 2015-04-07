int pattern0 = analogReadFunction(4, 7);
int pattern1 = analogReadFunction(6, 7);
int pattern2 = analogReadFunction(8, 7);
int pattern3 = analogReadFunction(10, 7);

if (now > timerTestValue) {

	if (drumPatterns[pattern0][columnToPlay-1] == 1) {
		digitalWrite(digitalOutputs[0], HIGH);
		digitalWrite(digitalOutputs[0], LOW);
	}

	if (drumPatterns[pattern1][columnToPlay-1] == 1) {
		digitalWrite(digitalOutputs[1], HIGH);
		digitalWrite(digitalOutputs[1], LOW);
	}

	if (drumPatterns[pattern2][columnToPlay-1] == 1) {
		digitalWrite(digitalOutputs[2], HIGH);
		digitalWrite(digitalOutputs[2], LOW);
	}

	if (drumPatterns[pattern3][columnToPlay-1] == 1) {
		digitalWrite(digitalOutputs[3], HIGH);
		digitalWrite(digitalOutputs[3], LOW);
	}

	lastColumnPlayed = now; // blir nuvarande millisec

	columnToPlay++;

	if (columnToPlay > (noOfPatternColumns)) {
		columnToPlay = 1;
	}
}