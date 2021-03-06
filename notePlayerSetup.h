int noteOn = 0;
int noteColumnToPlay = 0;

int noteThatGoesOut[4];
int noteThatWentOut[4];

int playThisNote = 1;
const int noOfChords = 8;
int noteDistances[noOfChords][4] = {
	{0, 1, 2, 3},
	{0, 2, 3, 4},
	{0, 3, 4, 5},
	{0, 5, 3, 2},
	{0, 3, 7, 12},
	{0, 5, 9, 12},
	{0, 7, 10, 12},
	{10, 10, 10, 10}
};

int clockState = false;
int noteTriggerIn = false;

///////

///////

int incomingNoteOn = 0;

///////

int asrActive = 0;
int asr = 0;

///////

int pauseState = false;
int pauseTriggerIn = false;
int pauseNumberOfSteps = 0;

// int noteJumps[4] = {0, 0, 2, 2};

const int noOfNotePrograms = 16; // rows below, scales
const int noteSequenceLength = 32; // cols below
int notes1[noOfNotePrograms][noteSequenceLength] = {

	// 99 is empty and skip to reset
	// 66 is skip this note

	{ 1,  3,	5,	6,	8,	10,	 12,	13,	15,	17,	18,	20,	22,	24,	25,	27,	29,	30,	32,	34,	36,	37,	39,	41,	42,	44,	46,	48,	49,	51,	53,	54 }, // Major
	{ 1,	3,	4,	6,	8,  10,	 12,	13, 15,	16,	18,	20,	22,	24,	25,	27,	28,	30,	32,	34,	36,	37,	39,	40,	42,	44,	46,	48,	49,	51,	52,	54 }, // Minor
	{ 1,	3,	4,	6,	8,   9,	 12,	13, 15,	16,	18,	20,	21,	24,	25,	27,	28,	30,	32,	33,	36,	37,	39,	40,	42,	44,	45,	48,	49,	51,	52,	54 }, // Harmonic Minor
	{ 1,	3,	6,	8,	10,	13,	 15,	18, 20,	22,	25,	27,	30,	32,	34,	37,	39,	42,	44,	46,	49,	51,	54,	56,	58,	61,	63,	66,	68,	70,	73,	75 }, // Pentatonic Major
	{ 1,	4,	6,	8,	11,	13,	 16,	18, 20,	23,	25,	28,	30,	32,	35,	37,	40,	42,	44,	47,	49,	52,	54,	56,	59,	61,	64,	66,	68,	71,	73,	76 }, // Pentatonic Minor
	{ 1,	4,	6,	7,	8,  11,	 13,	16, 18,	19,	20,	23,	25,	28,	30,	31,	32,	35,	37,	40,	42,	43,	44,	47,	49,	52,	54,	55,	56,	59,	61,	64 }, // Pentatonic Blues
	{ 1,	3,	6,	8,	8,  11,	 13,	15, 18,	20,	20,	23,	25,	27,	30,	32,	32,	35,	37,	39,	42,	44,	44,	47,	49,	51,	54,	56,	56,	59,	61,	63 }, // Pentatonic Neutral
	{ 1,	4,	6,	7,	9,  11,	 12,	13, 16,	18,	19,	21,	23,	24,	25,	28,	30,	31,	33,	35,	36,	37,	40,	42,	43,	45,	47,	48,	49,	52,	54,	55 }, // Aeolian
	{ 1,	3,	4,	6,	8,  10,	 11,	13, 15,	16,	18,	20,	22,	23,	25,	27,	28,	30,	32,	34,	35,	37,	39,	40,	42,	44,	46,	47,	49,	51,	52,	54 }, // Dorian
	{ 1,	3,	5,	6,	8,  10,	 11,	13, 15,	17,	18,	20,	22,	23,	25,	27,	29,	30,	32,	34,	35,	37,	39,	41,	42,	44,	46,	47,	49,	51,	53,	54 }, // Mixolydian
	{ 1,	2,	4,	6,	8,   9,	 11,	13, 14,	16,	18,	20,	21,	23,	25,	26,	28,	30,	32,	33,	35,	37,	38,	40,	42,	44,	45,	47,	49,	50,	52,	54 }, // Phrygian
	{ 1,	3,	5,	7,	8,  10,	 12,	13, 15,	17,	19,	20,	22,	24,	25,	27,	29,	31,	32,	34,	36,	37,	39,	41,	43,	44,	46,	48,	49,	51,	53,	55 }, // Lydian
	{ 1,	2,	4,	6,	7,   9,  11,	13, 14,	16,	18,	19,	21,	23,	25,	26,	28,	30,	31,	33,	35,	37,	38,	40,	42,	43,	45,	47,	49,	50,	52,	54 }, // Locrian
	{ 1,	2,	4,	5,	7,   8,  10,	11, 13,	14,	16,	17,	19,	20,	22,	23,	25,	26,	28,	29,	31,	32,	34,	35,	37,	38,	40,	41,	43,	44,	46,	47 }, // Dim Half
	{ 1,	3,	4,	6,	7,   9,  10,	12, 13,	15,	16,	18,	19,	21,	22,	24,	25,	27,	28,	30,	31,	33,	34,	36,	37,	39,	40,	42,	43,	45,	46,	48 }, // Dim Whole
	{ 1,	3,	5,	7,	9,  11,	 13,	15, 17,	19,	21,	23,	25,	27,	29,	31,	33,	35,	37,	39,	41,	43,	45,	47,	49,	51,	53,	55,	57,	59,	61,	63 }  // Whole

};


//////////////// Sequencer

const int noteSequenceLengthSequencer = 8;
int noteColumnToPlaySequencer = 0;
int pauseSequencer[8] = {0,0,0,0,0,0,0,0};
long stepsSequencer = 0;

int noteNumber[4]; // The four output notes

int sequencerOn = 0;
int sequencerTriggerIn = false;

int sequencerTrigIn1 = false;
int sequencerClockState1 = false;

int sequencerTrigIn2 = false;
int sequencerClockState2 = false;

int sequencerNoteDistance = 0;


