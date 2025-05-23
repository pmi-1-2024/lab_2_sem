#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile || !outFile) {
        cerr << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    int n;
    if (!(inFile >> n)) {
        cerr << "Помилка зчитування кількості символів." << endl;
        return 1;
    }

    istream_iterator<char> inIter(inFile), eos;
    vector<char> symbols;
    copy_n(inIter, n, back_inserter(symbols));

    if (symbols.size() < n) {
        cerr << "Недостатньо символів у файлі." << endl;
        return 1;
    }

    vector<char> targets = { '+', '-', '*' };
    map<char, int> counts;

    for (char ch : targets) {
        counts[ch] = count_if(symbols.begin(), symbols.end(),
                              [ch](char c) { return c == ch; });
    }

    outFile << "Кількість '+': " << counts['+'] << endl;
    outFile << "Кількість '-': " << counts['-'] << endl;
    outFile << "Кількість '*': " << counts['*'] << endl;
    outFile << "Загальна кількість символів '+', '-', '*': "
            << (counts['+'] + counts['-'] + counts['*']) << endl;

    return 0;
}
