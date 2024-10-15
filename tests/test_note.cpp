#include <gtest/gtest.h>
#include "note.h"
#include <string>

TEST(TestNotes, CheckSharp) {
    amu::music::Note note("D#");
    std::string pitch = note.getPitch(); 
    ASSERT_EQ(pitch[1], '#'); 
    pitch.erase(0,1);
    ASSERT_EQ(pitch[0], '#'); 
}
TEST(TestNotes, CheckFlat) {
    amu::music::Note note("Db");
    std::string pitch = note.getPitch(); 
    ASSERT_EQ(pitch[1], 'b'); 
    pitch.erase(0,1);
    ASSERT_EQ(pitch[0], 'b'); 
}