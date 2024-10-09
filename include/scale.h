#ifndef SCALE_H
#define SCALE_H
#include <array>
#include <utility>
#include <vector>

#include "defines.h"
#include "note.h"

// Namespace Begins
NS_AMU_BEGINS
NS_MUSIC_BEGINS
class Scale {
       public:
        Scale();
        Scale(const Scale &obj);
        ~Scale();

       private:
        std::vector<Note> notes;
};

NS_ENDS      // music
    NS_ENDS  // amu

#endif