#include <gtest/gtest.h>
#include "note.h"
#include <string>

TEST(TestNotes, CheckSharp) {
    amu::music::Note note("C#");
    std::string pitch = note.getPitch(); 
    ASSERT_EQ(pitch[1], '#'); 
    pitch.erase(0,1);
    ASSERT_EQ(pitch[0], '#'); 
}
