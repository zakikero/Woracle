//
// Created by zakik on 1/13/2026.
//

#include "WordleSolver.h"

#include <algorithm>
#include <stdexcept>


void WordleSolver::addCodeInput(const std::string &codeInput) {
    this->codeInputs.push_back(codeInput);
}

void WordleSolver::addGuess(const std::string &wordGuessed, const std::string &codeInput) {
    guesses.emplace_back(wordGuessed, codeInput);
}

void WordleSolver::filterOutBlackLetters() {
    const auto it = std::ranges::remove_if(possibleWords,
                                           [this](const std::string &word) {
                                               return std::ranges::any_of(word, [this](const char &letter) {
                                                   return blackLetters.contains(letter);
                                               });
                                           }).begin();
    possibleWords.erase(it, possibleWords.end());
}

void WordleSolver::addBlackLetter(const char &blackLetter) {
    if (blackLetters.contains(blackLetter))
        throw std::runtime_error("Black Letter Already exists, algorithm error");

    blackLetters.insert(blackLetter);
}

void WordleSolver::getNextWordGuess() {
}

void WordleSolver::filterPossibleWords() {
}
