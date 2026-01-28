//
// Created by Admin on 1/23/2026.
//

#ifndef WORACLE_BENCHMARKCHRONO_H
#define WORACLE_BENCHMARKCHRONO_H
#include <chrono>
#include <iostream>


class BenchmarkChrono {
public:
    void start();

    void stop();

    [[nodiscard]] long long getElapsedNanoseconds() const;

    void displayElapsedNanoseconds() const {
        std::cout << std::endl;
        std::cout << "Elapsed time: " << getElapsedNanoseconds() << " ns " << std::endl;
        std::cout << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
};


#endif //WORACLE_BENCHMARKCHRONO_H
