#ifndef CHEATSHEET_H
#define CHEATSHEET_H

#include <iostream>
#include <string>
using namespace std;

class CheatSheet {
protected:
    string subject;
    int number;

public:
    CheatSheet() : subject("Unknown"), number(0) {}
    CheatSheet(string subj, int num) : subject(subj), number(num) {}
    virtual ~CheatSheet() {}

    virtual void readData(istream& is) = 0;
    virtual void print(ostream& os) const = 0;
    virtual bool isElectronic() const = 0;

    bool operator<(const CheatSheet& other) const {
        return number < other.number;
    }

    string getSubject() const { return subject; } 

    friend ostream& operator<<(ostream& os, const CheatSheet& cs) {
        cs.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, CheatSheet& cs) {
        cs.readData(is);
        return is;
    }
};

#endif
