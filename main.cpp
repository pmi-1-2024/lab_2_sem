#include <iostream>
#include <vector>
#include <windows.h>
#include "utils.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    vector<char> symbols;
    cout << "Введіть послідовність символів (до першого '!'): ";

    char ch;
    while (cin.get(ch)) {
        if (ch == '!') break;
        symbols.push_back(ch);
    }

    cout << "а) Кількість пропусків: " << countSpaces(symbols) << endl;
    cout << "б) Містить 'ю': " << (containsChar(symbols, 'ю') ? "так" : "ні") << endl;
    cout << "в) Усі символи зі слова 'dino': " << (containsAllLetters(symbols, "dino") ? "так" : "ні") << endl;

    return 0;
}
