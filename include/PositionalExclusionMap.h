//
// Created by Admin on 1/20/2026.
//

#ifndef WORACLE_CHARACTEREXCLUDER_H
#define WORACLE_CHARACTEREXCLUDER_H
#include <string>
#include <unordered_set>
#include <vector>

class PositionalExclusionMap {
public:
    PositionalExclusionMap();

    void addExclusion(const char &c, const size_t &position);

    [[nodiscard]] bool isCharExcluded(const char &c, const size_t &position) const;

    [[nodiscard]] bool isWordExcluded(const std::string &word) const;

private:
    std::vector<std::unordered_set<char> > charExclusionVector;
};


#endif //WORACLE_CHARACTEREXCLUDER_H
