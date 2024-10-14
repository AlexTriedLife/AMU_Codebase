#ifndef WAVE_H
#define WAVE_H

#include "defines.h"
#include "iWave.h"
#include <SDL3/SDL.h>
#include <vector>
#include <cmath>

NS_AMU_BEGINS
NS_AUDIO_BEGINS

class Wave : public amu::interface::iWave {
       public:
        // default constructor
        Wave();
        // constructor
        Wave(double amplitude, double frequency, double phase,
             double sampleRate);
        // copy constructor
        Wave(const Wave& wave);
        ~Wave() override;
        

        // getters
        double getAmplitude() const override;
        double getFrequency() const override;
        double getPhase() const override;
        double getSampleRate() const override;

        // setters
        void setAmplitude(double amplitude) override;
        void setFrequency(double frequency) override;
        void setPhase(double phase) override;
        void setSampleRate(double sampleRate) override;


       private:
        double amplitude;
        double frequency;
        double phase;
        double sampleRate;
};
NS_ENDS  // audio
    NS_ENDS  // amu
#endif 