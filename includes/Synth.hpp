
#ifndef SYNTH_HPP
# define SYNTH_HPP

# include <Arduino.h>
# include <Audio.h>
# include <Wire.h>
# include "./Oscillator.hpp"
# include "./Constantes.h"

extern AudioPlayQueue    queue1;

//ma classe Synth
class Synth
{
public:
  void  readParam();
  void  fillFrequencies();
  int   getBuffer();
  int   fillBuffer();
  //void  postTraitement(); => a rajouter plus tard pour tout ce qui est filtres, fx, etc...
  void  playBuffer();

private:
  Oscillator  Osc1;
  //Oscillator  Osc2; => plus tard
  int         activeNotes;
  int16_t     *buffer;
};

#endif
