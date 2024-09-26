#ifndef UTIL_TIME_H
#define UTIL_TIME_H
#include <chrono>

#include "defines.h"


NS_AMU_BEGINS
NS_UTIL_BEGINS

using TimePoint = std::chrono::high_resolution_clock::time_point;

// get current time
inline TimePoint now() { return std::chrono::high_resolution_clock::now(); }

inline std::chrono::milliseconds durationMilSec(const TimePoint& start,
                                                const TimePoint& end) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                     start);
}
inline std::chrono::seconds durationSec(const TimePoint& start,
                                        const TimePoint& end) {
        return std::chrono::duration_cast<std::chrono::seconds>(end - start);
}
inline std::chrono::microseconds durationMicSec(const TimePoint& start,
                                                const TimePoint& end) {
        return std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start);
}

NS_ENDS      // util
    NS_ENDS  // amu
#endif     
