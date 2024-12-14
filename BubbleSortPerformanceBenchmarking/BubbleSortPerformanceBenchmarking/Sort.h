#ifndef SORT_H
#define SORT_H

#include <vector>
#include <utility>

template <typename T, typename Compare>
void bubbleSort(std::vector<T>& vec, Compare relation) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (!relation(vec[j], vec[j + 1])) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template <typename T, typename Compare>
void bubbleSortReduced(std::vector<T>& vec, Compare relation) {
    for (size_t i = 0; i < vec.size(); ++i) {
        bool swapped = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (!relation(vec[j], vec[j + 1])) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename T, typename Compare>
void bubbleSortWithFlag(std::vector<T>& vec, Compare relation) {
    size_t n = vec.size();
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (!relation(vec[i - 1], vec[i])) {
                std::swap(vec[i - 1], vec[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

#endif