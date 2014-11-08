static const int thing[13][3] = {
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
	{0, 83, 167},
};

int const noOfDrumPrograms = 1;
int const noOfRows = 11;
int const noOfColumns = 32;
int drums[noOfDrumPrograms][noOfRows][32] = {

	{
	 // 1  2  3  4  5  6  7  8   	 1  2  3  4  5  6  7  8
		{ 1, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0,    0, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 1, 0, 0, 0,    1, 0, 0, 0, 1, 0, 0, 0,    1, 0, 0, 0, 1, 0, 0, 0,    1, 0, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0,    1, 0, 1, 0, 1, 0, 1, 0,    1, 0, 1, 0, 1, 0, 1, 0,    1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1, 1, 1, 1, 1, 1 },
		
		{ 0, 1, 0, 1, 0, 1, 0, 1,    0, 1, 0, 1, 0, 1, 0, 1,    0, 1, 0, 1, 0, 1, 0, 1,    0, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 0, 0, 1, 0,    0, 0, 1, 0, 0, 0, 1, 0,    0, 0, 1, 0, 0, 0, 1, 0,    0, 0, 1, 0, 0, 0, 1, 0 },

		{ 1, 0, 0, 1, 0, 0, 1, 0,    0, 1, 0, 0, 1, 0, 0, 1,    1, 0, 0, 1, 0, 0, 1, 0,    0, 1, 0, 0, 1, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0,    0, 0, 1, 0, 0, 0, 0, 1,    1, 0, 0, 0, 0, 1, 0, 0,    0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 1, 0,    0, 0, 0, 0, 1, 0, 0, 0,    0, 0, 1, 0, 0, 0, 0, 0,    1, 0, 0, 0, 0, 0, 0, 0 }
	} 
};

int lastColumnPlayed = 0;
int timeHasPassed = 0;
int columnToPlay = 1;
int now = 100;

int isThisATrigger[noOfRows] = {1,1,1,1,1,1,1,1,1,1,1};
int everyOtherTrigger[noOfRows] = {1,1,1,1,1,1,1,1,1,1,1};

int pinOffset = 22;

// randomization/probability
int randValueRemove = 0;
int randValueAdd = 0;

// for the on/off switch on clock in
int inputIsHigh = 0;
int digState[2] = {LOW, LOW};  // start with both set low

int drumLoops = 0;
int drumDivision[6] = {1, 2, 4, 8, 16, 32};    

int sixth = 0;
int seventh = 0;
int eighth = 0;


int envelope[noOfRows] = {0,0,0,0,0,0,0,0,0,0,0};
int envelopeMax = 2560;
int envelopeIncrementSteps = 80;
int envelopeIncrementCurrentOne = 1;
