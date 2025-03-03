#include "Address.h"
Address::Address(): index("none"), city("none"), street("none") {}
Address::Address(string i, string c, string s) : index(i), city(c), street(s) {}

string Address::getCity() const { return city; }

string Address::getFullAddress() const { return index + ", " + city + ", " + street; }

void Address::display(ostream& os) const {
    os << "Address: " << getFullAddress() << endl;
}

void Address::read(istream& is)
{
    is >> this->index >> this->city >> this->street;
}

istream& operator>>(istream& is, Address& a)
{
    a.read(is);
    return is;
}

ostream& operator<<(ostream& os, Address& a)
{
    a.display(os);
    return os;
}
