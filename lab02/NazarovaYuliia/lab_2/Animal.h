#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Animal
{
protected:
    string name;
    int birthYear;

public:
    Animal() : name(""), birthYear(0) {}
    Animal(string name, int birthYear) : name(name), birthYear(birthYear) {}

    virtual void print(ostream& os) const;
    virtual void read(istream& is);

    int getBirthYear() const { return birthYear; }

    virtual ~Animal() {}

    bool operator<(const Animal& other) const {
        return birthYear < other.birthYear;
    }
    friend ostream& operator<<(ostream& os, const Animal& a) {
        a.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, Animal& a) {
        a.read(is);
        return is;
    }
};

