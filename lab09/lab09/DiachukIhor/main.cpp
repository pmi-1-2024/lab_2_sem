#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

struct NotAsterisk {
    bool operator()(char c) const {
        return c != '*';
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input || !output) {
        cerr << "Помилка відкриття файлів!" << endl;
        return 1;
    }

    int n;
    input >> n;

    cout << "Кількість символів: " << n << endl;

    vector<char> symbols;
    istream_iterator<char> in_iter(input);
    istream_iterator<char> eof;

    copy_n(in_iter, n, back_inserter(symbols));

    cout << "Вхідна послідовність: ";
    for (char c : symbols) {
        cout << c;
    }
    cout << endl;

    vector<char> filtered;
    copy_if(symbols.begin(), symbols.end(), back_inserter(filtered), NotAsterisk());

    vector<char> result;
    for (char c : filtered) {
        result.push_back(c);
        result.push_back(c);
    }

    cout << "Результат: ";
    for (char c : result) {
        cout << c;
    }
    cout << endl;

    ostream_iterator<char> out_iter(output, "");
    copy(result.begin(), result.end(), out_iter);

    return 0;
}