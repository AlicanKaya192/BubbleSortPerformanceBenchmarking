#ifndef VECTOR_GENERATOR_H
#define VECTOR_GENERATOR_H

#include <vector>
#include <algorithm>
#include <random>

template <typename T>
std::vector<T> generateRandomVector(size_t size, T min = 0, T max = 100) {
    std::vector<T> vec(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis(min, max);

    for (auto& val : vec) {
        val = dis(gen);
    }
    return vec;
}

template <typename T>
std::vector<T> generateSortedVector(size_t size) {
    std::vector<T> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = static_cast<T>(i);
    }
    return vec;
}

template <typename T>
std::vector<T> generateReverseSortedVector(size_t size) {
    std::vector<T> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = static_cast<T>(size - i - 1);
    }
    return vec;
}

#endif