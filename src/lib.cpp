#include "lib.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;


void processFile(const string &filename, vector<std::string> &vec) {
    // open File
    ifstream file(filename);
    if (!file.is_open()) {
        perror("Could not open file");
        return;
    }

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        vec.push_back(line);
    }
}

// Note: Received AI assistance (Claude) for this function
// extract words from line and store in map
void processLine(const string &line, unordered_map<string, int> &word_count) {
    istringstream iss(line);
    string word;

    while (iss >> word) {
        //Remove punctuation
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        //Convert to lowercase for consistency
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        //Only add non-empty words
        if (!word.empty()) {
            word_count[word]++;
        }
    }
}

// Note: Received AI assistance (Claude) for this function
// store string to map
void string_to_map(const string &msg, unordered_map<string, int> &word_count) {
    // Create a string stream from the input message
    istringstream iss(msg);

    // Declare variables to store word and count
    string word;
    int count;

    // Try to extract the word and count from the message
    if (iss >> word >> count) {
        // Add or update the word in the map
        word_count[word] = count;
    }
}

// Note: Received AI assistance (Claude) for this function
void update_word_count(unordered_map<string, int>& total_word_count, const string& result_line) {
    istringstream iss(result_line);
    string word;
    int count;
    if (iss >> word >> count) {
        total_word_count[word] += count;
    }
}

// Print final word count results
void print_results(const unordered_map<string, int>& total_word_count) {
    cout << "\nFinal Word Count:\n";
    for (const auto& pair : total_word_count) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
