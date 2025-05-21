#include "utils.h"
#include <set>

int countSpaces(const std::vector<char>& data) {
    int count = 0;
    for (char c : data)
        if (c == ' ') ++count;
    return count;
}

bool containsChar(const std::vector<char>& data, char target) {
    for (char c : data)
        if (c == target) return true;
    return false;
}

bool onlyFromWord(const std::vector<char>& data, const std::string& word) {
    std::set<char> allowed(word.begin(), word.end());
    for (char c : data) {
        if (c != ' ' && !allowed.count(c))
            return false;
    }
    return true;
}
