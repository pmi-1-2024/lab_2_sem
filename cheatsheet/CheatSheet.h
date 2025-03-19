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
    CheatSheet() : subject(""), number(0) {}
    CheatSheet(const string& subj, int num) : subject(subj), number(num) {}
    virtual ~CheatSheet() {}

    virtual void readData(istream& is) = 0;
    virtual void print(ostream& os) const = 0;
    virtual bool isElectronic() const = 0; // метод для перевірки типу

    string getSubject() const { return subject; }
    int getNumber() const { return number; }

    bool operator<(const CheatSheet& other) const {
        return number < other.number; // за номером
    }
};

#endif