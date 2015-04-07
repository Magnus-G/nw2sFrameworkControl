int interval = analogReadFunction(10, 7);

if (now > timerTestValue) {
	for (int row=1; row<noOfRowsForMathDrum; row++) { // vertical, outputs. start with output 0... first row
		if (columnToPlay % row == 0) {
			digitalWrite(digitalOutputs[row-1], HIGH);
		}
	} // rows done

	lastColumnPlayed = now; 

	columnToPlay++;

	if (columnToPlay > (noOfColumns)) {
		columnToPlay = 1;
	}
}

for (int row=1; row<noOfRowsForMathDrum; row++) { // vertical, outputs. start with output 0... first row
	unsigned long currentMillis = millis();

	if(currentMillis - previousMillis > interval) {
	  previousMillis = currentMillis;   
	  digitalWrite(digitalOutputs[row-1], LOW);
	}
}