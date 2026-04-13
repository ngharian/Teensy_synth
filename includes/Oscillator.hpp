
#ifndef OSCILLATOR_HPP
# define OSCILLATOR_HPP

# include "./Constantes.h"
# include <Arduino.h>

class Oscillator
{
private:
	//Osc var
	int		octave;
	float	phase;
	int		typeWave;

	//ADSR var
	int		attackValue;
	float	attackFactor;
	int		decayValue;
	float	decayFactor;
	float	sustainValue;
	int		releaseValue;
	float	releaseFactore;
	float	phases[NUMBER_NOTES];

	float	getWaveAmp(float phase);
	float	applyADSR(float currentAmp);
public:
	float			frequencies[NUMBER_NOTES];

	float	applyOctave(float frequencie);
	void	resetPhase();
	void	readParam();
	float	getCurrentAmp(int n);
	void	incrementPhase(int index);
};

# endif
