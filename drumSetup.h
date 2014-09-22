int const noOfDrumPrograms = 1;
int const noOfRows = 16;
int drums[noOfDrumPrograms][noOfRows][16] = {

	{
	// 1  2  3  4  5  6  7  8   	1  2  3  4  5  6  7  8
		{1, 0, 0, 0, 1, 0, 0, 0,    1, 0, 0, 0, 1, 0, 0, 0}, // bass
		{0, 0, 1, 1, 0, 0, 1, 0,    0, 0, 1, 1, 0, 0, 1, 0}, // snare
		{1, 0, 1, 0, 1, 0, 1, 0,    1, 0, 1, 0, 1, 0, 1, 0}, // hihat    
		{0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 1, 0, 1, 1}, // tom
		{1, 0, 0, 1, 0, 0, 1, 0,    0, 1, 0, 0, 1, 0, 0, 1}, // syncopation
		{1, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0}, // seldom
		{1, 0, 1, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0}, // double start
		{1, 0, 1, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0}, // double start
		{1, 1, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0},

		{1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1}
	} 
};

int lastColumnPlayed = 0;
int timeHasPassed = 0;
int columnToPlay = 1;
int now = 100;

int isThisATrigger[noOfRows] = {1,1,1,1,1,1,1,1};
int everyOtherTrigger[noOfRows] = {1,1,1,1,1,1,1,1};

int pinOffset = 22;

// randomization/probability
int randValueSubtract = 1023;
int randValueAdd = 1023;

// for the on/off switch on clock in
int inputIsHigh = 0;
int digState[2] = {LOW, LOW};  // start with both set low

int drumLoops = 0;
int drumDivision[6] = {1, 2, 4, 8, 16, 32};    

int sixth = 0;
int seventh = 0;
int eighth = 0;
