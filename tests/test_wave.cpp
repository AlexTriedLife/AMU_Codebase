#include "wave.h"
#include <gtest/gtest.h>
#include "defines.h"
USE_NS_AUDIO;


TEST(WaveTest, TestDefaultConstructor) {
        Wave wave;
        EXPECT_EQ(wave.getAmplitude(), 0);
        EXPECT_EQ(wave.getFrequency(), 0);
        EXPECT_EQ(wave.getPhase(), 0);
        EXPECT_EQ(wave.getSampleRate(), 0);
}

TEST(WaveTest, TestConstructor) {
        Wave wave(1, 2, 3, 4);
        EXPECT_EQ(wave.getAmplitude(), 1);
        EXPECT_EQ(wave.getFrequency(), 2);
        EXPECT_EQ(wave.getPhase(), 3);
        EXPECT_EQ(wave.getSampleRate(), 4);
}

TEST(WaveTest, TestCopyConstructor) {
        Wave wave(1, 2, 3, 4);
        Wave wave2(wave);
        EXPECT_EQ(wave2.getAmplitude(), 1);
        EXPECT_EQ(wave2.getFrequency(), 2);
        EXPECT_EQ(wave2.getPhase(), 3);
        EXPECT_EQ(wave2.getSampleRate(), 4);
}

TEST(WaveTest, TestSetters) {
        Wave wave;
        wave.setAmplitude(1);
        wave.setFrequency(2);
        wave.setPhase(3);
        wave.setSampleRate(4);
        EXPECT_EQ(wave.getAmplitude(), 1);
        EXPECT_EQ(wave.getFrequency(), 2);
        EXPECT_EQ(wave.getPhase(), 3);
        EXPECT_EQ(wave.getSampleRate(), 4);
}



