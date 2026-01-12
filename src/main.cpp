#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

const string DEFAULT_DICTIONNARY_PATH = "./fiveLetterWords/words.txt";

vector<string> readDictionnary(const string &path) {
    ifstream wordReader(path);
    vector<string> dictionary;
    string word;

    cout << "Reading dictionary from " << path << endl;
    while (getline(wordReader, word)) {
        cout << word << endl;
        dictionary.push_back(word);
    }
    cout << dictionary.size() << endl;
    cout << "Finished reading dictionary." << endl;

    wordReader.close();
    return dictionary;
}

vector<string> timedReadDictionnary(const string &path) {
    const chrono::time_point<chrono::system_clock> start =
            chrono::high_resolution_clock::now();

    vector<string> dictionary = readDictionnary(path);

    const chrono::time_point<chrono::system_clock> end = chrono::high_resolution_clock::now();
    const chrono::duration<long long, ratio<1, 1000> > duration = std::chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Elapsed time: " << duration.count() << "ms\n";

    return dictionary;
}


int main(int argc, char *argv[]) {

    vector<string> dictionary = timedReadDictionnary(DEFAULT_DICTIONNARY_PATH);

    return 0;
}
