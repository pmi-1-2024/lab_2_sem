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
    string getName() const { return name; }

    virtual void display(ostream& os) const = 0;
    virtual bool matchesCriteria(const string& parameter) const = 0;

    friend ostream& operator<<(ostream& os, const Animal& animal) {
        animal.display(os);
        return os;
    }
};

#endif
