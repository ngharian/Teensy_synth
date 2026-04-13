
#include "../includes/Synth.hpp"

void	Synth::readParam()
{
	Osc1.readParam();
	//Osc2.readParam();
}

void	Synth::fillFrequencies()
{
	activeNotes = 0;

	for (int i = 0; i < NUMBER_NOTES; i++)
	{
		int readed = digitalRead(pinArray[i]);
		if (!readed)
		{
			if (releaseTime[i] == 0)
			{
				if (triggerTime[i] != 0)
				{
					triggerTime[i] = 0;
					releaseTime[i] = millis();
					activeNotes++;
				}
				else
				{
					Osc1.frequencies[i] = 0;
					//Osc2.frequencies[i] = 0;
					continue;
				}
			}
		}
		if(triggerTime[i] == 0)
		{
			triggerTime[i] = millis()
			releaseTime[i] = 0;
		}
		activeNotes++;
		Osc1.frequencies[i] = Osc1.applyOctave(noteArray[i]);
		//Osc2.frequencies[i] = Osc2.applyOctave(noteArray[i]);
  		}
	if (activeNotes == 0)
	{
		Osc1.resetPhase();
		//Osc2.resetPhase();
	}                                                                                                                                                                               
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
		for (int n = 0; n < NUMBER_NOTES; n++) //mettre cette boucle dans getCurrentAmp? comme ca on calcule et applique l'adsr une seule fois par echantillonage au lieu de jusqua NUMBER_NOTES fois
		{
			if (Osc1.frequencies[n]) // rajouter condition si l'osc est actif ou non pour pouvoir les activer/desactiver.
				mixedSignal += Osc1.getCurrentAmp(n);
			//if (Osc2.frequencies[n])
				//mixedSignal += Osc2.getCurrentAmp(n);
			Osc1.incrementPhase(n);
			//Osc2.incrementPhase(n);
		}
		buffer[i] = (int16_t)((mixedSignal / NUMBER_NOTES) * 32767.0);
		Serial.println(buffer[i]);
	}
	return (1);
}

void	Synth::playBuffer()
{
	queue1.playBuffer();
}
