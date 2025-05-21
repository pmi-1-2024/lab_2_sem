#include <iostream>
#include <vector>
#include <windows.h>
#include "utils.h"
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    vector<char> symbols;
    cout << "������ ����������� ������� (�� ������� '!'): ";

    char ch;
    while (cin.get(ch)) {
        if (ch == '!') break;
        symbols.push_back(ch);
    }

    cout << "�) ʳ������ ��������: " << countSpaces(symbols) << endl;
    cout << "�) ̳����� '�': " << (containsChar(symbols, '�') ? "���" : "�") << endl;
    cout << "�) �� ������� � ����� 'dino': " << (onlyFromWord(symbols, "dino") ? "���" : "�") << endl;

    return 0;
}
