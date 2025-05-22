#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;


struct IsChar {
    char ch;
    IsChar(char c) : ch(c) {}
    bool operator()(const string& s) const {
        return s == string(1, ch);
    }
};

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        cerr << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    int n;
    inFile >> n;
    istream_iterator<string> inIter(inFile), eos;
    vector<string> symbols(inIter, eos);
    vector<char> targets = { '+', '-', '*' };
    map<char, int> counts;

    for (char ch : targets) {
        int count = count_if(symbols.begin(), symbols.end(), IsChar(ch));
        counts[ch] = count;
    }

    outFile << "Кількість '+': " << counts['+'] << endl;
    outFile << "Кількість '-': " << counts['-'] << endl;
    outFile << "Кількість '*': " << counts['*'] << endl;
    outFile << "Загальна кількість символів '+', '-', '*': "
        << (counts['+'] + counts['-'] + counts['*']) << endl;

    return 0;
}
