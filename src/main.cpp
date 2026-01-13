#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

const string DEFAULT_DICTIONARY_PATH = "./fiveLetterWords/words.txt";

vector<string> readDictionary(const string &path) {
    ifstream wordReader(path);
    if (wordReader.is_open()) throw std::runtime_error("Could not open file at: " + path);

    vector<string> dictionary;
    string word;

    cout << "Reading dictionary from " << path << endl;
    while (getline(wordReader, word)) {
        // cout << word << endl;
        dictionary.push_back(word);
    }
    cout << dictionary.size() << endl;
    cout << "Finished reading dictionary." << endl;

    return dictionary;
}

vector<string> timedReadDictionary(const string &path) {
    const chrono::time_point<chrono::system_clock> start =
            chrono::high_resolution_clock::now();

    vector<string> dictionary = readDictionary(path);

    const chrono::time_point<chrono::system_clock> end = chrono::high_resolution_clock::now();
    const chrono::duration<long long, ratio<1, 1000> > duration = std::chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Elapsed time: " << duration.count() << "ms\n";

    return dictionary;
}


int main(int argc, char *argv[]) {

    vector<string> dictionary = timedReadDictionary(DEFAULT_DICTIONARY_PATH);

    cout << "input the word FLUTE to start and give me the color of each letters in sequence \nfor example : ygbyb " << endl;


    return 0;
}
