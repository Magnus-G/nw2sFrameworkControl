using namespace nw2s;

PinDigitalIn digitalInputs[9] = {
	
	DUE_IN_DIGITAL_NOISE,
	DUE_IN_D0,
	DUE_IN_D1,
	DUE_IN_D2,
	DUE_IN_D3,
	DUE_IN_D4,
	DUE_IN_D5,
	DUE_IN_D6,
	DUE_IN_D7	
};

PinAnalogIn inputs[12] = {
	
	DUE_IN_A00,
	DUE_IN_A01,
	DUE_IN_A02,
	DUE_IN_A03,
	DUE_IN_A04,
	DUE_IN_A05,
	DUE_IN_A06,
	DUE_IN_A07,
	DUE_IN_A08,
	DUE_IN_A09,
	DUE_IN_A10,
	DUE_IN_A11
	
};

PinAnalogOut outpins[16] = {
	
	DUE_SPI_4822_00,
	DUE_SPI_4822_01,
	DUE_SPI_4822_02,
	DUE_SPI_4822_03,
	DUE_SPI_4822_04,
	DUE_SPI_4822_05,
	DUE_SPI_4822_06,
	DUE_SPI_4822_07,
	DUE_SPI_4822_08,
	DUE_SPI_4822_09,
	DUE_SPI_4822_10,
	DUE_SPI_4822_11,
	DUE_SPI_4822_12,
	DUE_SPI_4822_13,
	DUE_SPI_4822_14,
	DUE_SPI_4822_15

};

int values[11] = {
	
	-5000,
	-4000,
	-3000,
	-2000,
	-1000,
	0,
	1000,
	2000,
	3000,
	4000,
	5000
};

bool checkToggle = false;
long nextToggleTime = 0;

AnalogOut* outputs[16];
int counter = 0;

PinDigitalOut digitalOutputs[16] = {
	
	DUE_OUT_D00,
	DUE_OUT_D01,
	DUE_OUT_D02,
	DUE_OUT_D03,
	DUE_OUT_D04,
	DUE_OUT_D05,
	DUE_OUT_D06,
	DUE_OUT_D07,
	DUE_OUT_D08,
	DUE_OUT_D09,
	DUE_OUT_D10,
	DUE_OUT_D11,
	DUE_OUT_D12,
	DUE_OUT_D13,
	DUE_OUT_D14,
	DUE_OUT_D15,

};

static const int semitones[48] = {
  0, 
  83, 
  167, 
  250, 
  333, 
  417, 
  500, 
  583, 
  667, 
  750, 
  833, 
  917,

  1000, 
  1083, 
  1167, 
  1250, 
  1333, 
  1417, 
  1500, 
  1583, 
  1667, 
  1750, 
  1833, 
  1917,

  2000, 
  2083, 
  2167, 
  2250, 
  2333, 
  2417, 
  2500, 
  2583, 
  2667, 
  2750, 
  2833, 
  2917,
  
  3000, 
  3083, 
  3167, 
  3250, 
  3333, 
  3417, 
  3500, 
  3583, 
  3667, 
  3750, 
  3833, 
  3917,
 }; 