#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

#include "DictionaryReader.h"

const std::string DEFAULT_DICTIONARY_PATH = "./fiveLetterWords/words.txt";

bool isCodeInputValid(const std::string& codeInput)
{
    if (codeInput.length() != 5) return false;

    return std::ranges::all_of(codeInput, [](const char c)
    {
        return c == 'g' || c == 'y' || c == 'b';
    });
}


int main(int argc, char* argv[])
{
    std::vector<std::string> dictionary = timedReadDictionary(DEFAULT_DICTIONARY_PATH);

    std::cout << "input the word FLUTE to start and give me the color of each letters in sequence \nfor example : ygbyb " <<
        std::endl;

    std::string codeInput;
    while (true)
    {
        std::cout << "Enter code :\t";
        std::cin >> codeInput;
        if (!isCodeInputValid(codeInput)) continue;



    }
    return 0;
}
