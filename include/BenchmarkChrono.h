//
// Created by Admin on 1/23/2026.
//

#ifndef WORACLE_BENCHMARKCHRONO_H
#define WORACLE_BENCHMARKCHRONO_H
#include <chrono>


class BenchmarkChrono {
public:
    void start();

    void stop();

    [[nodiscard]] long long getElapsedNanoseconds() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
};


#endif //WORACLE_BENCHMARKCHRONO_H
