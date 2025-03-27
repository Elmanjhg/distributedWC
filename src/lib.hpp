#pragma once // ensures file is included only once

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Function to store the contents of a file in a vector as text chunks
void processFile(const string &filename, vector<string> &vec);

// Function to process a line of text and count the frequency of each word
void processLine(const string &line, unordered_map<string, int> &word_count);

// Function to store words in a map
void string_to_map(const string &msg, unordered_map<string, int> &word_count);

// Function to update the total word count with the results from a worker
void update_word_count(unordered_map<string, int>& total_word_count, const string& result_line);

// Function to print the word count
void print_results(const unordered_map<string, int>& word_count);