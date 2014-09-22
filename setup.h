void setup() {
	Serial.begin(19200);
	Serial.println("Starting...");

	/* Always set up the gain mode first - use HIGH if you are biased for -10V - +10V */
	b::cvGainMode = CV_GAIN_LOW;

	/* Set up a clock to have something to watch :P */
	EventManager::initialize();

	/* Setup analog inputs */
	analogReadResolution(12);

	/* Iterate each of the outputs and set to 0mV */
	for (int i = 0; i < 16; i++) {
		outputs[i] = AnalogOut::create(outpins[i]);
		outputs[i]->outputCV(0000);
	}
}