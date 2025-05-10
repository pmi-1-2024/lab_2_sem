#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(const string& name, int year) : name(name), birthYear(year) {}

int Animal::getBirthYear() const {
    return birthYear;
}

const string& Animal::getName() const {
    return name;
}