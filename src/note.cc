#include "note.h"

USE_NS_MUSIC;

Note::Note()
    : pitches(
          {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}) {}
Note::Note(const Note &obj)
    : pitches(
          {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"}) {}

Note::~Note() {}
