#pragma once
#include <iostream>
#include <string>
using namespace std;

class CheatSheet {
protected:
    string subject;
    int number;

public:
    CheatSheet(const string& subject = "", int number = 0);
    virtual ~CheatSheet();

    string getSubject() const;
    int getNumber() const;

    virtual void print(ostream& os) const;
    virtual void read(istream& is);

    bool operator<(const CheatSheet& other) const;

    friend ostream& operator<<(ostream& os, const CheatSheet& cheatSheet);
    friend istream& operator>>(istream& is, CheatSheet& cheatSheet);
};