#ifndef CHEATSHEET_H
#define CHEATSHEET_H
#include <iostream>
#include <string>
using namespace std;
struct CheatSheet {
    string subject;
    int number;
    CheatSheet(string sb = "", int n = 0) : subject(sb), number(n) {}

    friend ostream& operator<<(ostream& os, const CheatSheet& cheatsheet) {
        os << "Subject:" << cheatsheet.subject << "\nNumber:" << cheatsheet.number;
        return os;
    }
    friend istream& operator>>(istream& is, CheatSheet& cheatsheet) {
        cout << "Enter cheat sheet subject:";
        is >> cheatsheet.subject;
        cout << "Enter cheat sheet number:";
        is >> cheatsheet.number;
        return is;
    }
};
#endif