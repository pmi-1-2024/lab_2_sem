#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int year) : name(name), birthYear(year) {}

int Animal::getBirthYear() const {
    return birthYear;
}
