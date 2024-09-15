#include "note.h"

USE_NS_MUSIC;
Note::Note(std::string pitch)
{
    setPitch(pitch);
}
Note::Note(const Note &obj) {}

std::string Note::getPitch()    {
    return m_pitch;
}

void Note::setPitch(std::string pitch)
{
    if (isalpha(pitch[0]))  {
        std::toupper(pitch[0]);
    }
    
    if(std::find(pitches.begin(), pitches.end(), pitch) != pitches.end())   {
        m_pitch = pitch;
    }
    else    {
        std::cerr << pitch << " is not a valid note" << std::endl;
    }
}

void Note::printNoteInfo()   {
    std::cout << "Pitch of the note is " << m_pitch << "\n";


    std::cout << std::endl;
}
