#include "Donkey.h"

void Donkey::print(ostream& out) const {
    Animal::print(out);
    out << ", Type: " << type << ", Height: " << height;
}