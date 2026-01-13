//
// Created by zakik on 1/13/2026.
//

#ifndef WORACLE_WORDLESOLVER_H
#define WORACLE_WORDLESOLVER_H
#include <string>
#include <vector>


class WordleSolver
{
public:
    explicit WordleSolver(const std::vector<std::string>& dictionary): possibleWords(dictionary) {}

    void addCodeInput(const std::string& codeInput);
    void getNextWordGuess();

private:
    void filterPossibleWords();

    std::vector<std::string> possibleWords;
    std::vector<std::string> codeInputs;
};


#endif //WORACLE_WORDLESOLVER_H
