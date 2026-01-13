//
// Created by zakik on 1/13/2026.
//

#include "DictionaryReader.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> readDictionary(const std::string& path)
{
    std::ifstream wordReader(path);
    if (!wordReader.is_open()) throw std::runtime_error("Could not open file at: " + path);

    std::vector<std::string> dictionary;
    std::string word;

    std::cout << "Reading dictionary from " << path << std::endl;
    while (getline(wordReader, word))
    {
        // cout << word << endl;
        dictionary.push_back(word);
    }
    std::cout << dictionary.size() << std::endl;
    std::cout << "Finished reading dictionary." << std::endl;

    return dictionary;
}

std::vector<std::string> timedReadDictionary(const std::string& path)
{
    const std::chrono::time_point<std::chrono::system_clock> start =
        std::chrono::high_resolution_clock::now();

    std::vector<std::string> dictionary = readDictionary(path);

    const std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<long long, std::ratio<1, 1000>> duration = std::chrono::duration_cast<
        std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time: " << duration.count() << "ms\n";

    return dictionary;
}