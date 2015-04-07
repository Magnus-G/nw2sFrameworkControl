// each decay increment will be this long
int envelopeIncrementValue = delayTimeConstrained / envelopeIncrementSteps;

if (now > (lastColumnPlayed + (envelopeIncrementValue * envelopeIncrementCurrentOne))) {

	// envelopes or levels
	// if (envelopeActive) {

	// 	// decrease the Envelopes
	// 	if(envelopeDecay > envelopeZeroDecay) {
	// 		for (int row=1; row<noOfRows; row++) { 
	// 			int envelopeDecreasePerStep = (envelopeMax / envelopeIncrementSteps) * 2;
	// 			envelope[row-1] -= envelopeDecreasePerStep * (envelopeDecreasePerStep / envelopeDecay); // 2560 div by 80 is 32 
	// 			if (envelope[row-1] < 0) {
	// 				envelope[row-1] = 0;
	// 			}
	// 			outputs[row-1]->outputCV(envelope[row-1]); 
	// 		}
	// 	}

	// 	// if negative decay
	// 	else if(envelopeDecay < envelopeZeroDecay) {
	// 		for (int row=1; row<noOfRows; row++) { 
	// 			int envelopeIncreasePerStep = envelopeMax / envelopeIncrementSteps;
	// 			envelope[row-1] += envelopeIncreasePerStep * (envelopeIncreasePerStep / envelopeDecay+1); // 2560 div by 80 is 32 
	// 			if (envelope[row-1] > envelopeMax) {
	// 				envelope[row-1] = 0;
	// 			}
	// 			outputs[row-1]->outputCV(envelope[row-1]); 
	// 		}	
	// 	}

	// 	envelopeIncrementCurrentOne++;

	// 	if(envelopeIncrementCurrentOne == envelopeIncrementSteps) {
	// 		envelopeIncrementCurrentOne = 1;
	// 	}
	// }
}