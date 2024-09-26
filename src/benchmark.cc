#include "benchmark.h"

USE_NS_SYS;

Measure::Measure() {}

Measure::Measure(const Measure& obj) {}

Measure::~Measure() {}

void Measure::startMeasurement() {
        m_start_time = std::chrono::high_resolution_clock::now();
}
void Measure::endMeasurement() {
        m_end_time = std::chrono::high_resolution_clock::now();
}

// Getters and setters
void Measure::start_time(std::chrono::high_resolution_clock::time_point& time) {
        m_end_time = time;
}
void Measure::end_time(std::chrono::high_resolution_clock::time_point& time) {
        m_end_time = time;
}

const std::chrono::high_resolution_clock::time_point& Measure::start_time()
    const {
        return m_start_time;
}
const std::chrono::high_resolution_clock::time_point& Measure::end_time()
    const {
        return m_end_time;
}
