#include "utils.h"
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

int countSpaces(const  vector<char>& data) {
    return  count_if(data.begin(), data.end(), [](char c) { return c == ' '; });
}

bool containsChar(const  vector<char>& data, char target) {
    return  any_of(data.begin(), data.end(), [target](char c) { return c == target; });
}

bool containsAllLetters(const  vector<char>& data, const  string& word) {
     set<char> required(word.begin(), word.end());
     set<char> found;

     insert_iterator< set<char>> inserter(found, found.begin());

     for_each(data.begin(), data.end(), [&](char c) {
        if (required.count(c)) {
            *inserter++ = c;
        }
        });

    return found == required;
}
