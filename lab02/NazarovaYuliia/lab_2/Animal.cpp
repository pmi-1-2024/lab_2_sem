#include "Animal.h"

void Animal::print(ostream& os) const {
    os << "Name: " << name << ", Birth Year: " << birthYear;
}
void Animal::read(istream& is) {
    is >> name >> birthYear;
}