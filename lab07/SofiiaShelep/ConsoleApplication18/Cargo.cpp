#include "Cargo.h"

istream& operator>>(istream& in, Cargo& c)
{
    getline(in, c.type);
    in >> c.weight;
    in.ignore();
    return in;
}

ostream& operator<<(ostream& out, const Cargo& c)
{
    out << c.type << " (" << c.weight << " kg)";
    return out;
}
