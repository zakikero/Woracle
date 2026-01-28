//
// Created by Admin on 1/23/2026.
//

#include "BenchmarkChrono.h"

void BenchmarkChrono::start() {
    startTime = std::chrono::high_resolution_clock::now();
}
void BenchmarkChrono::stop() {
    endTime = std::chrono::high_resolution_clock::now();
}
long long BenchmarkChrono::getElapsedNanoseconds() const {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}