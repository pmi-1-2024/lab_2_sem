#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <cctype>

using namespace std;

bool isNonAlnum(char c) {
    return !isalnum(c);  
}

void toLowercase(char& c) {
    c = tolower(c);  
}

int main() {
    try {
        ifstream inFile("input.txt");
        ofstream outFile("output.txt");

        if (!inFile) throw runtime_error("Failed to open input file");
        if (!outFile) throw runtime_error("Failed to open output file");

        vector<char> symbols;
        copy_if(istream_iterator<char>(inFile), istream_iterator<char>(),
            inserter(symbols, symbols.end()),
            [](char c) { return c != ' '; });

        symbols.erase(remove_if(symbols.begin(), symbols.end(), isNonAlnum),
            symbols.end());

        for_each(symbols.begin(), symbols.end(), toLowercase);

        copy(symbols.begin(), symbols.end(), ostream_iterator<char>(outFile));

        return 0;
    }

    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unknown error occurred" << endl;
        return 2;
    }
}