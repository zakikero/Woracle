//
// Created by Admin on 1/22/2026.
//


#include <algorithm>
#include <string>

bool isCodeInputValid(const std::string &codeInput) {
    if (codeInput.length() != 5) return false;

    return std::ranges::all_of(codeInput, [](const char c) {
        return c == 'g' || c == 'y' || c == 'b';
    });
}

std::string toUpper(const std::string &input) {
    std::string transformedInput = input;
    std::ranges::transform(transformedInput, transformedInput.begin(),
                           [](const unsigned char &c) { return std::toupper(c); });
    return transformedInput;
}
