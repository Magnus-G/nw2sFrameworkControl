// const int littleStarNotes = 16;
// const int fourNotes = 4;

// int hej[2] = {littleStarNotes, fourNotes};

// int notesLittleStar[littleStarNotes] = {1, 1, 8, 8, 10, 10, 8, 0, 6, 6, 5, 5, 3, 3, 1, 0};
// int notesFour[fourNotes] = {1, 2, 3, 4};

int playThisNote = 1;

int noteDistances[2] = {7, 12};

const int noteSequenceLength = 16;

// 99 is empty and skip to reset

// | 5 A     || 6 A#     | 7 B      | 8 C     | 9 C#    |10 D    |11 D#    | 12    |
  // | 0(13) E || 1(14) F  | 2(15) F# | 3 G     | 4 G#    | 5 A    | 6 A#    | 7     |


const int noOfNotePrograms = 3;
int notes1[noOfNotePrograms][noteSequenceLength] = {

	{ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16 },
	{ 1,  1,  8,  8, 10, 10,  8,  0,  6,  6,  5,  5,  3,  3,  1,  0 },
	{ 1,  3,  4,  6,  8,  9, 11, 13,  1,  3,  4,  6,  8,  9, 11, 13 }

};
const int noteDistanceFrom1 = 7;

int notes2[noteSequenceLength];
const int noteDistanceFrom2 = 5;

int notes3[noteSequenceLength];

int noteToPlay = 0;
int tuning = 85; // best so far = 91 or 85?