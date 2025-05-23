#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <string>

int countSpaces(const std::vector<char>& data);
bool containsChar(const std::vector<char>& data, char target);
bool containsAllLetters(const std::vector<char>& data, const std::string& word);

#endif
