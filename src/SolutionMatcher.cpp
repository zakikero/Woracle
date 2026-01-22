//
// Created by Admin on 2026-01-16.
//

#include "SolutionMatcher.h"

#include <stdexcept>

void SolutionMatcher::addLetterAtPosition(const char &letter, const size_t &position) {
    if (position >= 5) {
        throw std::out_of_range("Position must be between 0 and 4");
    }
    solutionPattern[position] = letter;
}

std::string SolutionMatcher::getSolutionPattern() {
    return solutionPattern;
}

bool SolutionMatcher::isWordMatching(const std::string &word) const {
    for (size_t i = 0; i < solutionPattern.length(); i++) {
        if (solutionPattern[i] != '.' && word[i] != solutionPattern[i]) {
            return false;
        }
    }
    return true;
}
