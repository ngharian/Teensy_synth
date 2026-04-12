
#include "./includes/Synth.hpp"

// --- Configuration Audio Teensy ---
AudioPlayQueue			queue1;
AudioOutputI2S			i2s1;
AudioConnection			patchCord1(queue1, 0, i2s1, 0);
AudioConnection			patchCord2(queue1, 0, i2s1, 1);
AudioControlSGTL5000	sgtl5000_1;

//mon objet synth global
Synth	synth;

void	initSineTable()
{
	for (int i = 0; i < SINE_TABLE_SIZE; i++)
		sineTable[i] = sinf((float)i * 2.0f * PI / (float)SINE_TABLE_SIZE);
}

void setup() {
	initSineTable();
	//Initialisation du Shield
	sgtl5000_1.enable();
	sgtl5000_1.volume(0.9);

	//Initialisation lecture potards
	AudioMemory(10);
	analogReadResolution(12);
	pinMode(OCT_PIN, INPUT);
	pinMode(WAVE_PIN, INPUT);
}

void	loop() {
	synth.readParam();
	if (synth.getBuffer()) //recupere le bufffer de l'audio Queue pour l'intant, je veux creer ma propre gestion de buffer apres
		return ;
	synth.fillFrequencies(); //lis les touches et les lies a la frequence correspondant a la note de la touche
	if (!synth.fillBuffer())  // calcule les amplitudes des differents osc + eventuels envelopes/lfo plus tard eventuellement
		return ;
	//synth.postTraitement(); => plus tard, pour gerer fx, filtres, etc...
	synth.playBuffer(); //dis a l'audio queue de jouer son buffer, je veux creer ma propre gestion plus tard
}
