# Teensy Synth

A small personal hardware synth project built around a Teensy 4.1 and a REV Shield, using Teensyduino to generate audio in real time.

This project is a beginner-friendly introduction to synth design: it explores how oscillator waves, note frequencies, octave control, and audio buffering can be combined to create a simple playable synth from scratch.

## Project goal

The aim of this project is to:
- learn the basics of digital audio generation,
- understand how a microcontroller can output sound,
- experiment with simple waveforms,
- build a compact synth prototype using accessible hardware.

## Hardware

- Teensy 4.1
- REV Shield
- 12-note keyboard mapped on digital pins
- Analog potentiometers for octave and waveform selection

## Features

- 12-note keyboard input
- octave modifier
- waveform selector (saw, square, triangle, sine)
- real-time audio synthesis generated on the Teensy
- simple mixing of multiple active notes
- audio buffer sent to the I2S output

## How it works

The Teensy reads the state of the keyboard pins to know which notes are currently pressed. It then computes the corresponding frequencies and mixes them in the audio buffer.

Each note is processed by an oscillator object:
- the waveform type is chosen by the user,
- the octave changes the frequency range,
- the phase advances over time to generate the sound,
- the resulting samples are summed and sent to the audio output.

## Required tools

To compile and upload this project, you need:

- Arduino IDE or Visual Studio Code with Arduino support
- Teensyduino installed
- USB cable for the Teensy 4.1
- REV Shield connected correctly

## Setup

1. Install Teensyduino.
2. Open the project in the Arduino IDE.
3. Select the correct board (Teensy 4.1)
4. Select the correct port.
5. Compile and upload the sketch.

## Usage

- Press the note buttons on the REV Shield setup.
- Adjust the octave knob to change pitch range.
- Adjust the waveform knob to switch between saw, square, triangle, and sine.
- Listen to the generated sound through the audio output.

## Notes

This project is deliberately simple and educational. It is not a full commercial synthesizer, but it is a great first step into the world of digital synthesis and embedded audio.

It introduces several core concepts used in more advanced synth designs:
- oscillators
- waveshaping
- frequency control
- sample generation and real-time audio output

## Future ideas

Possible improvements for the next version:
- add envelopes
- add filters
- add MIDI input
- support more than one voice
