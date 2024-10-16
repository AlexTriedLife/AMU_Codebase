#ifndef DEFINES_H
#define DEFINES_H
// Namespace macros
#define NS_AMU_BEGINS namespace amu {
#define NS_MUSIC_BEGINS namespace music {
#define NS_MATH_BEGINS namespace math {
#define NS_AUDIO_BEGINS namespace audio {
#define NS_STRING_BEGINS namespace string {
#define NS_FILE_BEGINS namespace file {
#define NS_GRAPHICS_BEGINS namespace graphics {
#define NS_SYS_BEGINS namespace sys {
#define NS_UTIL_BEGINS namespace util {
#define NS_INTERFACE_BEGINS namespace interface {
#define NS_ENDS \
        }  // Add comment to end of line to illustrate which namespace ends

// Use macros
#define USE_NS_AMU using namespace amu
#define USE_NS_GRAPHICS using namespace amu::graphics
#define USE_NS_AUDIO using namespace amu::audio
#define USE_NS_MUSIC using namespace amu::music
#define USE_NS_MATH using namespace amu::math
#define USE_NS_STRING using namespace amu::string
#define USE_NS_FILE using namespace amu::file
#define USE_NS_SYS using namespace amu::sys
#define USE_NS_UTIL using namespace amu::util
#define USE_NS_INTERFACE using namespace amu::interface

#endif  // DEFINES_H