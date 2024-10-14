#include "wave.h"
#include <numbers>
#include <SDL3/SDL.h> // Include SDL header

USE_NS_AUDIO;
// default constructor
Wave::Wave() : amplitude(0), frequency(0), phase(0), sampleRate(0) {}

// constructor
Wave::Wave(double amplitude, double frequency, double phase, double sampleRate)
    : amplitude(amplitude),
      frequency(frequency),
      phase(phase),
      sampleRate(sampleRate) {}

// copy constructor
Wave::Wave(const Wave& wave)
    : amplitude(wave.amplitude),
      frequency(wave.frequency),
      phase(wave.phase),
      sampleRate(wave.sampleRate) {}

// destructor
Wave::~Wave() = default;

// getters
double Wave::getAmplitude() const { return amplitude; }

double Wave::getFrequency() const { return frequency; }

double Wave::getPhase() const { return phase; }

double Wave::getSampleRate() const { return sampleRate; }

// setters
void Wave::setAmplitude(double amplitude) { this->amplitude = amplitude; }

void Wave::setFrequency(double frequency) { this->frequency = frequency; }

void Wave::setPhase(double phase) { this->phase = phase; }

void Wave::setSampleRate(double sampleRate) { this->sampleRate = sampleRate; }

