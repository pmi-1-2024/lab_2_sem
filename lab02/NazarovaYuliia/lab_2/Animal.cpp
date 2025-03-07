#include "Animal.h"

void Animal::print(ostream& out) const {
    out << "Name: " << name << ", Birth Year: " << birthYear;
}