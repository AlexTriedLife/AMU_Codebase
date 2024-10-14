#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include "defines.h"
#include "util_time.h"

USE_NS_UTIL;

static void TestNow() {
    start_end se;
    se.start = now();
    std::this_thread::sleep_for(milliseconds(2));
    se.end = now();
    
    ASSERT_GT(se.end, se.start);
}

static void TestDurationSec() {
    start_end se;
    se.start = now();
    std::this_thread::sleep_for(milliseconds(2));
    se.end = now();
    ASSERT_EQ(durationMilSec(se.start, se.end), std::chrono::duration_cast<milliseconds>(se.end - se.start));
}

TEST(TestUtilTime, TestNow) {
    TestNow();
}

TEST(TestUtilTime, TestDurationSec) {
    TestDurationSec();
}