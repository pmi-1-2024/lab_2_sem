#include "Cargo.h"

istream& operator>>(istream& in, Cargo& c)
{
    in >> c.type >> c.weight;
    return in;
}

ostream& operator<<(ostream& out, const Cargo& c)
{
    out << c.type << " (" << c.weight << " kg)";
    return out;
}
