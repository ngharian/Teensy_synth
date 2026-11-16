
#ifndef OSCILLATOR_HPP
# define OSCILLATOR_HPP

# include "./Constantes.h"
# include <Arduino.h>

class Oscillator
{
private:
  int	octave;
  float	phase;
  int	typeWave;
  
  float	phases[NUMBER_NOTES];

  float	getWaveAmp(float phase);

public:
  float	frequencies[NUMBER_NOTES];

  float	applyOctave(float frequencie);
  void	resetPhase();
  void	readParam();
  float	getCurrentAmp(int n);
  void	incrementPhase(int index);
};

# endif
