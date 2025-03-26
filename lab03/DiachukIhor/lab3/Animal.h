#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
    int birthYear;
public:
    Animal(const string& name, int year);
    virtual ~Animal() = default;
    int getBirthYear() const;
    const string& getName() const;
    virtual void print(ostream& out) const = 0;
};

#endif