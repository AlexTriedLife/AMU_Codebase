#ifndef NOTE_H
#define NOTE_H
#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

#include "defines.h"

// Namespace Begins
NS_AMU_BEGINS
NS_MUSIC_BEGINS
class Note {
       public:
        Note(std::string pitch);
        Note(const Note &obj);

        void printNoteInfo();
        void normalizePitch(const std::string &pitch);

        static constexpr std::array<const char *, 12> pitches{
            "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
        static constexpr std::array<std::pair<const char *, const char *>, 14>
            enharmonicEquivalents{
                std::make_pair("C#", "Db"), std::make_pair("D#", "Eb"),
                std::make_pair("E#", "F"),  std::make_pair("F#", "Gb"),
                std::make_pair("G#", "Ab"), std::make_pair("A#", "Bb"),
                std::make_pair("B#", "C"),  std::make_pair("Cb", "B"),
                std::make_pair("Db", "C#"), std::make_pair("Eb", "D#"),
                std::make_pair("Fb", "E"),  std::make_pair("Gb", "F#"),
                std::make_pair("Ab", "G#"), std::make_pair("Bb", "A#")};

        std::string getPitch();

       private:
        std::string m_pitch;

        void setPitch(std::string pitch);
        // lambda syntax, empty capture list
        static const std::unordered_map<std::string, std::string> pitchMap;
};

NS_ENDS      // music
    NS_ENDS  // amu
// Namespace ends

#endif