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

    virtual void display(ostream& os) const = 0;
    virtual bool isWhiteHorse() const { return false; }
    virtual bool isShortDonkey() const { return false; }

    friend istream& operator>>(istream& is, Animal*& animal);
};

#endif 
