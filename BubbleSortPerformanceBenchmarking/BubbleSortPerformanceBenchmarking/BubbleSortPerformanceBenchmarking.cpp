#include "Sort.h"
#include "Benchmark.h"
#include "vectorGenerator.h"
#include <iostream>

int main() {
    size_t size = 5000;

    std::vector<int> randomVec = generateRandomVector<int>(size);

    Benchmark<std::chrono::microseconds> benchmark;
    auto relation = [](int a, int b) { return a < b; };

    benchmark.reset();
    bubbleSort(randomVec, relation);
    int duration = benchmark.elapsed();
    std::cout << "Classical Bubble Sort Time: " << duration << " microseconds" << std::endl;

    return 0;
}