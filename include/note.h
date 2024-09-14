#ifndef NOTE_H
#define NOTE_H
#include "defines.h"
#include <array>
#include <utility>

// Namespace Begins
NS_AMU_BEGINS
NS_MUSIC_BEGINS

class Note {
public:
  Note();
  Note(const Note &obj);
  ~Note();

private:
  std::pair<char, int> pitch;
  const std::array<const char *, 12> pitches;
};

NS_MUSIC_ENDS
NS_AMU_ENDS
// Namespace ends

#endif