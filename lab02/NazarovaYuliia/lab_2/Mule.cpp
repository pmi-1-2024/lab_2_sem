#include "Mule.h"

void Mule::print(ostream& out) const {
    Animal::print(out);
    out << ", Color: " << Horse::getColor() << ", Type: " << type << ", Height: " << height << ", Nickname: " << nickname;
}
