#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <chrono>

#include "defines.h"

NS_AMU_BEGINS
NS_SYS_BEGINS

class Measure {
       public:
        Measure();
        Measure(const Measure& obj);
        ~Measure();

        void startMeasurement();
        void endMeasurement();

        // setters
        void start_time(std::chrono::high_resolution_clock::time_point& time);
        void end_time(std::chrono::high_resolution_clock::time_point& time);

        // getters
        const std::chrono::high_resolution_clock::time_point& start_time()
            const;
        const std::chrono::high_resolution_clock::time_point& end_time() const;

       private:
        std::chrono::high_resolution_clock::time_point m_start_time;
        std::chrono::high_resolution_clock::time_point m_end_time;

        std::chrono::duration<double> getDuration() const;
};

NS_ENDS      // sys
    NS_ENDS  // amu
#endif
