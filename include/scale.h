#ifndef SCALE_H
#define SCALE_H
#include "defines.h"
#include "note.h"
#include <array>
#include <vector>
#include <utility>

// Namespace Begins
NS_AMU_BEGINS
NS_MUSIC_BEGINS
class Scale 
{
public:
    Scale();
    Scale(const Scale &obj);
    ~Scale();
private:
    std::vector<Note> notes;

};




NS_AMU_ENDS
NS_MUSIC_ENDS

#endif