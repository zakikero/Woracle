//
// Created by Admin on 2026-01-16.
//

#ifndef WORACLE_REGEXBUILDER_H
#define WORACLE_REGEXBUILDER_H
#include <string>

class SolutionMatcher {
public:
    SolutionMatcher() : solutionPattern(".....") {
    };

    void addLetterAtPosition(const char &letter, const size_t &position);

    std::string getSolutionPattern();

    [[nodiscard]] bool isWordMatching(const std::string &word) const;

    [[nodiscard]] bool isComplete() const {
        return solutionPattern.find('.') == std::string::npos;
    }

private:
    std::string solutionPattern;
};

#endif //WORACLE_REGEXBUILDER_H
