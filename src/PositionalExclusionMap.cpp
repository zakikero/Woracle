//
// Created by Admin on 1/20/2026.
//

#include "../include/PositionalExclusionMap.h"

#include <algorithm>
#include <functional>
#include <stdexcept>


PositionalExclusionMap::PositionalExclusionMap() {
    charExclusionVector.reserve(5);
    for (size_t i = 0; i < 5; i++)
        charExclusionVector.emplace_back();
}

void PositionalExclusionMap::addExclusion(const char &c, const size_t &position) {
    charExclusionVector.at(position).insert(c);
}

bool PositionalExclusionMap::isCharExcluded(const char &c, const size_t &position) const {
    return charExclusionVector.at(position).contains(c);
}

bool PositionalExclusionMap::isWordExcluded(const std::string &word) const {
    if (word.length() != charExclusionVector.size())
        throw std::runtime_error("Word length does not match exclusion map size.");

    for (size_t i = 0; i < word.length(); i++)
        if (isCharExcluded(word[i], i))
            return true;
    return false;
}
