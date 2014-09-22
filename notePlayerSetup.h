int playThisNote = 1;
int noteDistances[2] = {7, 12};
const int noteSequenceLength = 16;

// 99 is empty and skip to reset
const int noOfNotePrograms = 16; // rows below
int notes1[noOfNotePrograms][noteSequenceLength] = {

	{ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16 },
	{ 1,  1,  8,  8, 10, 10,  8,  0,  6,  6,  5,  5,  3,  3,  1,  0 },
	{ 1,  3,  4,  6,  8,  9, 11, 13,  1,  3,  4,  6,  8,  9, 11, 13 },
	{	0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
	{	0,  7, 10,  7,  9,  5,  7,  3,  2,  9, 12,  9, 11,  7,  9,  5 },
	{	0,  1,  0,  2,  0,  3,  0,  4,  0,  1,  0,  2,  0,  3,  0,  4 }, 
	{	0,  2,  3,  3,  7,  3,  5,  5,  2,  4,  5,  5,  9,  5,  7,  7 }, 
	{	0,  8,  7,  5,  3,  5,  7, 10,  0,  8,  7,  5,  3,  5,  7, 10 }, 
	{	0, 10,  0,  8,  0,  7,  3,  5,  2, 12,  2, 10,  2,  9,  5,  7 }, 
	{	0,  7,  3,  0,  9,  5,  9, 10,  0,  7,  3,  0,  9,  5,  9, 10 }, 
	{	0,  0,  1,  0,  0,  2,  0,  3,  0,  0,  3,  0,  0,  2,  0,  1 },  
	{	0,  0,  1,  0,  0,  6,  0,  3,  0,  0,  6,  0,  0,  3,  0,  1 },
	{	0,  0,  1,  0,  0,  6,  0,  3,  0,  0,  6,  0,  0,  3,  0,  1 },
	{	0,  0,  1,  0,  0,  6,  0,  3,  0,  0,  6,  0,  0,  3,  0,  1 },
	{	0,  0,  1,  0,  0,  6,  0,  3,  0,  0,  6,  0,  0,  3,  0,  1 },
	{	0,  0,  1,  0,  0,  6,  0,  3,  0,  0,  6,  0,  0,  3,  0,  1 } 

};
const int noteDistanceFrom1 = 7;

int notes2[noteSequenceLength];
const int noteDistanceFrom2 = 5;

int notes3[noteSequenceLength];

int noteToPlay = 0;
int tuning = 86; // best so far 85?