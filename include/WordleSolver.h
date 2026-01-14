//
// Created by zakik on 1/13/2026.
//

#ifndef WORACLE_WORDLESOLVER_H
#define WORACLE_WORDLESOLVER_H
#include <string>
#include <vector>
#include <unordered_set>

const std::string DEFAULT_STARTING_WORD = "FLUTE";

class WordleSolver {
public:
    explicit WordleSolver(const std::vector<std::string> &dictionary) : possibleWords(dictionary) {
        guesses.reserve(5);
    }

    void addCodeInput(const std::string &codeInput);

    void addGuess(const std::string &wordGuessed, const std::string &codeInput);

    void getNextWordGuess();

private:
    void filterPossibleWords();

    void filterOutBlackLetters();
    void addBlackLetter(const char& blackLetter);

    std::unordered_set<char> blackLetters;

    std::vector<std::string> possibleWords;
    std::vector<std::pair<std::string, std::string> > guesses; // pair of <word guessed, code input>
    std::vector<std::string> codeInputs;
};


#endif //WORACLE_WORDLESOLVER_H
