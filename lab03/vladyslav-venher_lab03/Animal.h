#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int birthYear;

public:
    Animal(const string& name = "", int birthYear = 0)
        : name(name), birthYear(birthYear) {
    }
    virtual ~Animal() {}

    int getBirthYear() const { return birthYear; }
    const string& getName() const { return name; }
    virtual bool isWhiteHorse() const { return false; }
    virtual bool isShortDonkey() const { return false; }

    virtual void read(istream& is) = 0;
    virtual void print(ostream& os) const = 0;

    friend istream& operator>>(istream& is, Animal& a) {
        a.read(is);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Animal& a) {
        a.print(os);
        return os;
    }
};

#endif