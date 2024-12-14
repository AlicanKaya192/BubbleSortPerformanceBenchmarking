#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>

template <typename TimeUnit>
class Benchmark {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

public:
    Benchmark() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void reset() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    int elapsed() {
        endTime = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<TimeUnit>(endTime - startTime).count();
    }
};

#endif