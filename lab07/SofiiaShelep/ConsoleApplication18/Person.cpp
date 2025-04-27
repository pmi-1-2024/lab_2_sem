#include "Person.h"

istream& operator>>(istream& in, Person& p)
{
    in >> p.name >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p)
{
    out << p.name << " (" << p.age << " years)";
    return out;
}
