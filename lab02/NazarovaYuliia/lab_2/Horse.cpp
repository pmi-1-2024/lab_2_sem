#include "Horse.h"

void Horse::print(ostream& out) const {
    Animal::print(out);
    out << ", Color: " << color << ", Breed: " << breed;
}