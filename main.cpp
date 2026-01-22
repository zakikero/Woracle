#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <filesystem>

#include "DictionaryReader.h"
#include "HelperFunctions.h"
#include "WordleSolver.h"

const std::string DEFAULT_DICTIONARY_PATH = "../src/fiveLetterWords/words.txt";

int main() {
    WordleSolver solver(timedReadDictionary(DEFAULT_DICTIONARY_PATH));

    std::string codeInput;
    std::string currentGuess = solver.getInitialGuess();

    while (true) {
        std::cout << "Current guess :\t" << toUpper(currentGuess) << std::endl;

        std::cout << "Enter code :\t";
        std::cin >> codeInput;

        if (!isCodeInputValid(codeInput)) {
            std::cout << "Invalid code input. Please enter a 5-character string using 'g', 'y', and 'b' only." <<
                    std::endl;
            continue;
        }

        solver.processGuessResults(currentGuess, codeInput);

        if (solver.isSolutionFound()) {
            std::cout << "Solution found! The word is: " << toUpper(solver.getSolutionPattern()) << std::endl;
            break;
        }

        currentGuess = solver.getNextWordGuess();
    }
    return 0;
}
