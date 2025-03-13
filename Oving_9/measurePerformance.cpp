#include "Stopwatch.h"
#include <memory>
#include <array>
#include <iostream>


// BEGIN 1a
constexpr int iterations = 1000000;
constexpr int size = 10000;

double measurePerformanceUnique() {
    Stopwatch sw;
    sw.start();
    for (int i = 0; i < iterations; ++i) {
        std::unique_ptr<int> uniquePtr = std::make_unique<int>(i);
    }
    return sw.stop() / static_cast<double>(iterations);
}

double measurePerformanceShared() {
    Stopwatch sw;
    sw.start();
    for (int i = 0; i < iterations; ++i) {
        std::shared_ptr<int> sharedPtr = std::make_shared<int>(i);
    }
    return sw.stop() / static_cast<double>(iterations); 
}

double measurePerformanceStack() {
    Stopwatch sw;
    sw.start();
    for (int i = 0; i < iterations; ++i) {
        std::array<int, size> arr1;
    }
    return sw.stop() / static_cast<double>(iterations);
}

double measurePerformanceHeap() {
    Stopwatch sw;
    sw.start();
    for (int i = 0; i < iterations; ++i) {
        std::array<int, size>* arr2 = new std::array<int, size>;
        delete arr2;
    }
    return sw.stop() / static_cast<double>(iterations);
}
// END 1a