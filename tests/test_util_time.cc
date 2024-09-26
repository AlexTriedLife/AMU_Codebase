#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include "defines.h"
#include "util_time.h"

USE_NS_UTIL;

TEST(TestUtilTime, TestNow) {
    ASSERT_EQ(now(), std::chrono::high_resolution_clock::now());

    start_end se;
    se.start = now();
    std::this_thread::sleep_for(milliseconds(2));
    se.end = now();
    
    ASSERT_GT(se.end, se.start);

}

TEST(TestUtilTime, TestDurationSec) {
    start_end se;
    se.start = now();
    std::this_thread::sleep_for(milliseconds(2));
    se.end = now();
    ASSERT_EQ(durationMilSec(se.start, se.end), std::chrono::duration_cast<milliseconds>(se.end - se.start));



}