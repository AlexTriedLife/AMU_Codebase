#ifndef I_WAVE_H
#define I_WAVE_H

#include "defines.h"
NS_AMU_BEGINS
NS_INTERFACE_BEGINS
/*
 * @brief Interface for a wave
 * @details This interface is used to define the methods that a wave should have
 */

class iWave {
       public:
        virtual ~iWave() = default;
        // getters

        virtual double getAmplitude() const = 0;
        virtual double getFrequency() const = 0;
        virtual double getPhase() const = 0;
        virtual double getSampleRate() const = 0;

        // setters
        virtual void setAmplitude(double amplitude) = 0;
        virtual void setFrequency(double frequency) = 0;
        virtual void setPhase(double phase) = 0;
        virtual void setSampleRate(double sampleRate) = 0;
};

NS_ENDS  // interface
NS_ENDS  // amu

#endif