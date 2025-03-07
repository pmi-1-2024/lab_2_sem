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
    Animal(string name, int birthYear) : name(name), birthYear(birthYear) {}
    virtual void print(ostream& out) const;
    int getBirthYear() const { return birthYear; }
    virtual ~Animal() {}
};

