//
// Created by zakik on 1/13/2026.
//

#ifndef WORACLE_WORDLESOLVER_H
#define WORACLE_WORDLESOLVER_H
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

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

    void processGuessResults(const std::string &wordGuessed, const std::string &codeInput);

    std::string getNextWordGuess();

    void printGuessesStack();

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

    std::vector<std::string> possibleWords;
    std::queue<std::pair<std::string, std::string> > guesses; // pair of <word guessed, code input>
};


#endif //WORACLE_WORDLESOLVER_H
