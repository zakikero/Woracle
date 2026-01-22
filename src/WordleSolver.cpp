//
// Created by zakik on 1/13/2026.
//

#include "WordleSolver.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>


void WordleSolver::processGuessResults(const std::string &wordGuessed, const std::string &codeInput) {
    if (wordGuessed.length() != codeInput.length()) {
        throw std::invalid_argument("Word guessed and code input must have the same length.");
    }
    addGuess(wordGuessed, codeInput);
    
    // First pass: count green and yellow letters to know the minimum count
    std::unordered_map<char, int> greenYellowCount;
    for (size_t i = 0; i < codeInput.length(); i++) {
        char letter = wordGuessed[i];
        char codeChar = codeInput[i];
        
        if (codeChar == 'g' || codeChar == 'y') {
            greenYellowCount[letter]++;
        }
    }
    
    // Second pass: process each letter
    for (size_t i = 0; i < codeInput.length(); i++) {
        char letter = wordGuessed[i];

        if (const char codeChar = codeInput[i]; codeChar == 'b') {
            // A black letter means the solution has exactly the count we found in green/yellow
            // (or 0 if none were green/yellow)
            if (greenYellowCount.contains(letter)) {
                // There are some green/yellow instances, so exact count is known
                letterExactCount[letter] = greenYellowCount[letter];
            } else {
                // No green/yellow instances, so this letter doesn't appear at all
                addBlackLetter(letter);
            }
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
                      // Check if word contains any truly black letters (letters not in the solution at all)
                      for (const char &blackLetter : blackLetters) {
                          if (word.find(blackLetter) != std::string::npos) {
                              return true;
                          }
                      }
                      
                      // Check if word has the exact count for letters with known exact counts
                      for (const auto &[letter, exactCount] : letterExactCount) {
                          int count = 0;
                          for (const char &c : word) {
                              if (c == letter) {
                                  count++;
                              }
                          }
                          // Word must have exactly this many of this letter
                          if (count != exactCount) {
                              return true;
                          }
                      }
                      
                      return false;
                  });
}

void WordleSolver::filterOutYellowLetters() {
    std::erase_if(possibleWords,
                  [this](const std::string &word) {
                      return yellowExclusionsMap.isWordExcluded(word);
                  });
    std::erase_if(possibleWords, [this](const std::string &word) {
        // Remove words that do not contain all known yellow letters
        return std::ranges::any_of(yellowLetters, [&word](const char &yellowLetter) {
            return word.find(yellowLetter) == std::string::npos;
        });
    });
}

void WordleSolver::filterOutGreenLetters() {
    std::erase_if(possibleWords,
                  [this](const std::string &word) {
                      return !greenMatcher.isWordMatching(word);
                  });
}
