#ifndef DEFINES_H
#define DEFINES_H
// Namespace macros
#define NS_AMU_BEGINS namespace amu {
#define NS_AMU_ENDS  }
#define NS_MUSIC_BEGINS namespace music {
#define NS_MUSIC_ENDS  }
#define NS_STRING_BEGINS namespace string {
#define NS_STRING_ENDS }
#define NS_FILE_BEGINS namespace file {
#define NS_FILE_ENDS }
#define NS_GRAPHICS_BEGINS namespace graphics {
#define NS_GRAPHICS_ENDS }


// Use macros
#define USE_NS_AMU using namespace amu
#define USE_NS_GRAPHICS using namespace amu::graphics
#define USE_NS_MUSIC using namespace amu::music
#define USE_NS_STRING using namespace amu::string
#define USE_NS_FILE using namespace amu::file

#endif // DEFINES_H