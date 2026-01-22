//
// Created by zakik on 1/13/2026.
//

#ifndef WORACLE_WORDLESOLVER_H
#define WORACLE_WORDLESOLVER_H
#include <queue>
#include <random>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include "PositionalExclusionMap.h"
#include "SolutionMatcher.h"

constexpr std::size_t MAX_GUESS_AMOUNT = 6;
const std::string DEFAULT_STARTING_WORD = "FLUTE";


class WordleSolver {
public:
    explicit WordleSolver(const std::vector<std::string> &dictionary)
        : greenMatcher(SolutionMatcher()),
          possibleWords(dictionary) {
    }

    std::string getInitialGuess();

    void processGuessResults(const std::string &wordGuessed, const std::string &codeInput);

    std::string getNextWordGuess() const;

    void printGuessesStack() const;

    bool isSolutionFound() const {
        return greenMatcher.isComplete();
    }

    std::string getSolutionPattern() {
        return greenMatcher.getSolutionPattern();
    }

private:
    void addGuess(const std::string &wordGuessed, const std::string &codeInput);

    void filterPossibleWords();

    void filterOutBlackLetters();

    void filterOutGreenLetters();

    void filterOutYellowLetters();


    void addBlackLetter(const char &blackLetter);

    void addYellowLetter(const char &yellowLetter, const size_t &position);

    void addGreenLetter(const char &greenLetter, const size_t &position);

    std::unordered_set<char> blackLetters;
    std::unordered_set<char> yellowLetters;
    PositionalExclusionMap yellowExclusionsMap;
    SolutionMatcher greenMatcher;
    std::unordered_map<char, int> letterExactCount; // tracks exact count of letters we know about

    std::vector<std::string> possibleWords;
    std::queue<std::pair<std::string, std::string> > guesses; // pair of <word guessed, code input>
    std::mt19937 rng{std::random_device{}()};
};


#endif //WORACLE_WORDLESOLVER_H
