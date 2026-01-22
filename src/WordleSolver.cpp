//
// Created by zakik on 1/13/2026.
//

#include "WordleSolver.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>


void WordleSolver::processGuessResults(const std::string &wordGuessed, const std::string &codeInput) {
    addGuess(wordGuessed, codeInput);
    for (size_t i = 0; i < codeInput.length(); i++) {
        char letter = wordGuessed[i];

        if (const char codeChar = codeInput[i]; codeChar == 'b') {
            addBlackLetter(letter);
        } else if (codeChar == 'y') {
            addYellowLetter(letter, i);
        } else if (codeChar == 'g') {
            addGreenLetter(letter, i);
        } else {
            throw std::invalid_argument("Invalid code character: " + std::string(1, codeChar));
        }
    }

    filterPossibleWords();
}

std::string WordleSolver::getNextWordGuess() {
    printGuessesStack();

    if (possibleWords.empty()) {
        throw std::runtime_error("No possible words remaining for the next guess.");
    }

    const std::string nextGuess = possibleWords.front();
    std::cout << "Possible words remaining: " << possibleWords.size() << std::endl;
    std::cout << "next guess: " << nextGuess << std::endl;

    return nextGuess;
}

void WordleSolver::printGuessesStack() {
    std::queue<std::pair<std::string, std::string> > tempGuesses = guesses;
    std::cout << "Guesses made so far:" << std::endl;
    while (!tempGuesses.empty()) {
        const auto &[word, code] = tempGuesses.front();
        std::cout << "Word: " << word << ", Code: " << code << std::endl;
        tempGuesses.pop();
    }
}

void WordleSolver::addGuess(const std::string &wordGuessed, const std::string &codeInput) {
    guesses.emplace(wordGuessed, codeInput);
}

void WordleSolver::addBlackLetter(const char &blackLetter) {
    blackLetters.insert(blackLetter);
}

void WordleSolver::addYellowLetter(const char &yellowLetter, const size_t &position) {
    yellowExclusionsMap.addExclusion(yellowLetter, position);
    yellowLetters.insert(yellowLetter);
}

void WordleSolver::addGreenLetter(const char &greenLetter, const size_t &position) {
    greenMatcher.addLetterAtPosition(greenLetter, position);
}


void WordleSolver::filterPossibleWords() {
    filterOutBlackLetters();
    filterOutYellowLetters();
    filterOutGreenLetters();
}

void WordleSolver::filterOutBlackLetters() {
    std::erase_if(possibleWords,
                  [this](const std::string &word) {
                      return std::ranges::any_of(word, [this](const char &letter) {
                          return blackLetters.contains(letter);
                      });
                  });
}

void WordleSolver::filterOutYellowLetters() {
    std::erase_if(possibleWords,
                  [this](const std::string &word) {
                      return yellowExclusionsMap.isWordExcluded(word);
                  });
    std::erase_if(possibleWords, [this](const std::string &word) {
        return std::ranges::any_of(word, [this](const char &letter) {
                return !yellowLetters.contains(letter);
            });
    });
}

void WordleSolver::filterOutGreenLetters() {
    std::erase_if(possibleWords,
                  [this](const std::string &word) {
                      return !greenMatcher.isWordMatching(word);
                  });
}
