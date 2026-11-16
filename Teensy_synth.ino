
#include "./includes/Synth.hpp"

AudioPlayQueue			queue1;
AudioOutputI2S			i2s1;
AudioConnection			patchCord1(queue1, 0, i2s1, 0);
AudioConnection			patchCord2(queue1, 0, i2s1, 1);
AudioControlSGTL5000	sgtl5000_1;

Synth	synth;

void	initSineTable()
{
	for (int i = 0; i < SINE_TABLE_SIZE; i++)
		sineTable[i] = sinf((float)i * 2.0f * PI / (float)SINE_TABLE_SIZE);
}

void setup() {
	initSineTable();

	sgtl5000_1.enable();
	sgtl5000_1.volume(0.9);

	AudioMemory(10);
	analogReadResolution(12);
	pinMode(OCT_PIN, INPUT);
	pinMode(WAVE_PIN, INPUT);
}

void	loop() {
	synth.readParam();
	if (synth.getBuffer())
		return ;
	synth.fillFrequencies();
	if (!synth.fillBuffer())
		return ;
	synth.playBuffer();
}
