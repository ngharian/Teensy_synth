
#ifndef SYNTH_HPP
# define SYNTH_HPP

# include <Arduino.h>
# include <Audio.h>
# include <Wire.h>
# include "./Oscillator.hpp"
# include "./Constantes.h"

extern AudioPlayQueue queue1;


class Synth
{
public:
  void	readParam();
  void	fillFrequencies();
  int	getBuffer();
  int	fillBuffer();

  void	playBuffer();

private:
  Oscillator	Osc1;

  int			activeNotes;
  int16_t		*buffer;
};

#endif
