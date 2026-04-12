
#ifndef CONSTANTES_H
# define CONSTANTES_H

# define NUMBER_NOTES 12
# define SAMPLE_RATE 44100.0
# define SAW 0
# define SQUARE 1
# define TRI 2
# define SINE 3
# define SINE_TABLE_SIZE 2048
# define OCT_PIN A16
# define WAVE_PIN A17 

const float		noteArray[NUMBER_NOTES] = {523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880, 932.33, 987.77};
const int		pinArray[NUMBER_NOTES] = {28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
inline float	sineTable[SINE_TABLE_SIZE];

# endif
