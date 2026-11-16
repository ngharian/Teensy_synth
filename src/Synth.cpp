
#include "../includes/Synth.hpp"

void	Synth::readParam()
{
	Osc1.readParam();
}

void	Synth::fillFrequencies()
{
	activeNotes = 0;

	for (int i = 0; i < NUMBER_NOTES; i++)
	{
		int readed = digitalRead(pinArray[i]);
		if (!readed)
		{
			Osc1.frequencies[i] = 0;
			continue ;
		}
		activeNotes++;
		Osc1.frequencies[i] = Osc1.applyOctave(noteArray[i]);
  	}
	if (activeNotes == 0)
		Osc1.resetPhase();                                                                                                                                                                           
}

int	Synth::getBuffer()
{
	buffer = queue1.getBuffer();
	if (buffer == NULL)
		return (1);
	return (0);
}

int	Synth::fillBuffer()
{
	if (activeNotes == 0)
		return (0);

	for (int i = 0; i < 128; i++)
	{
		float mixedSignal = 0;
		for (int n = 0; n < NUMBER_NOTES; n++)
		{
			if (Osc1.frequencies[n])
				mixedSignal += Osc1.getCurrentAmp(n);
			Osc1.incrementPhase(n);
		}
		buffer[i] = (int16_t)((mixedSignal / NUMBER_NOTES) * 32767.0);
	}
	return (1);
}

void	Synth::playBuffer()
{
	queue1.playBuffer();
}
