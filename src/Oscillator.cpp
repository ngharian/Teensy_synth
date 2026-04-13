
#include "../includes/Oscillator.hpp"

float Oscillator::applyOctave(float frequencie)
{
	switch(octave)
	{
		case (0):
			return(frequencie / 4);
		case (1):
	  		return(frequencie / 2);
		case (3):
			return(frequencie * 2);
		case (4):
			return (frequencie * 4);
		default:
			return (frequencie);
	}
}

void	Oscillator::resetPhase()
{
	for (int i = 0; i < NUMBER_NOTES; i++)
		phases[i] = phase;
}

void	Oscillator::readParam()
{
	//rajouter lecture d'ADSR
	phase = 0; // rajouter la lecture plus tard  
	octave = map(analogRead(OCT_PIN), 0, 4096, 0, 4);
	typeWave = map(analogRead(WAVE_PIN), 0, 4096, 0, 3);
}

float	Oscillator::getCurrentAmp(int n)
{
	float	currentAmp;
	//applyLFO();
	currentAmp = getWaveAmp(phases[n]);
	currentAmp = applyADSR(currentAmp);
	return (currentAmp);
}

float	Oscillator::getWaveAmp(float currentPhase)
{
	float	currentAmp = 0;

	switch (typeWave)
	{
	case(SAW):
		currentAmp = (currentPhase * 2.0f - 1.0f);
		break ;
	case(SQUARE):
		currentAmp = (currentPhase < 0.5f) ? 1.0f : -1.0f;
		break ;
	case(TRI):
		currentAmp = (currentPhase < 0.5f) ? (4.0f * currentPhase - 1.0f) : (3.0f - 4.0f * currentPhase);
		break ;
	case(SINE):
		int index = (int)(currentPhase * (float)SINE_TABLE_SIZE);
		if (index >= SINE_TABLE_SIZE) index = 0;
			currentAmp = sineTable[index];
	 	break;
  	}
	return (currentAmp);
}

void	Oscillator::incrementPhase(int index)
{
	phases[index] += frequencies[index] / SAMPLE_RATE;
	if (phases[index] >= 1.0)
		phases[index] -= 1.0;
}

void	Oscillator::applyADSR(float currentAmp)
{
	unsigned long currentTime = millis();

	if (synth.triggerTime[i] != 0)
	{
		//calcul AttackDecay
	}
	else if (synth.releasTime[i])
		//calcul release
}