#include <gtest/gtest.h>

#include <chrono>
#include <thread>

void startMeasurement(std::chrono::high_resolution_clock::time_point& start) {
        start = std::chrono::high_resolution_clock::now();
}

void endMeasurement(std::chrono::high_resolution_clock::time_point& end) {
        end = std::chrono::high_resolution_clock::now();
}

TEST(TestBenchmark, TestTimerStart) {
        std::chrono::high_resolution_clock::time_point start_time;
        std::chrono::high_resolution_clock::time_point end_time;
        const int timer_duration{2};
        startMeasurement(start_time);
        std::this_thread::sleep_for(std::chrono::seconds(timer_duration));
        endMeasurement(end_time);
        auto elapsed_time = end_time - start_time;
        int elapsed_time_seconds =
            duration_cast<std::chrono::duration<int>>(elapsed_time).count();
        ASSERT_GT(elapsed_time_seconds, 0);
        ASSERT_EQ(elapsed_time_seconds, 2);
        std::cout << "Duration is" << elapsed_time_seconds << "\n";
}
