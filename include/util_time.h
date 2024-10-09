#ifndef UTIL_TIME_H
#define UTIL_TIME_H
#include <chrono>

#include "defines.h"

NS_AMU_BEGINS
NS_UTIL_BEGINS

using TimePoint = std::chrono::high_resolution_clock::time_point;
using minutes = std::chrono::minutes;
using seconds = std::chrono::seconds;
using milliseconds = std::chrono::milliseconds;
using microseconds = std::chrono::microseconds;

// get current time
inline TimePoint now() { return std::chrono::high_resolution_clock::now(); }

inline milliseconds durationMilSec(const TimePoint& start,
                                   const TimePoint& end) {
        return std::chrono::duration_cast<milliseconds>(end - start);
}
inline std::chrono::seconds durationSec(const TimePoint& start,
                                        const TimePoint& end) {
        return std::chrono::duration_cast<seconds>(end - start);
}
inline std::chrono::microseconds durationMicSec(const TimePoint& start,
                                                const TimePoint& end) {
        return std::chrono::duration_cast<microseconds>(end - start);
}

struct start_end {
        TimePoint start;
        TimePoint end;
};

NS_ENDS      // util
    NS_ENDS  // amu
#endif
