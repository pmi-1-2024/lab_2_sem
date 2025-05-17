#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

static bool is_comma(char c) {
    return c == ',';
}

static bool is_dot(char c) {
    return c == '.';
}

struct Replace3WithPlus {
    char operator()(char c) const {
        return (c == '3') ? '+' : c;
    }
};

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input || !output) {
        cerr << "File opening error" << endl;
        return 1;
    }

    istream_iterator<char> in_it(input), eof;
    vector<char> chars(in_it, eof);

    auto dot_it = find(chars.begin(), chars.end(), '.');

    chars.erase(remove_if(chars.begin(), dot_it, is_comma), dot_it);

    dot_it = find(chars.begin(), chars.end(), '.');

    if (dot_it != chars.end() && (dot_it + 1) <= chars.end()) {
        transform(dot_it + 1, chars.end(), dot_it + 1, Replace3WithPlus());
    }

    ostream_iterator<char> out_it(output);
    copy(chars.begin(), chars.end(), out_it);

    return 0;
}