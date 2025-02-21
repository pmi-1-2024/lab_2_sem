#include "Address.h"

Address::Address(string index, string city, string street)
    : index(index), city(city), street(street) {
}

void Address::display() const {
    cout << index << ", " << city << ", " << street << endl;
}

string Address::getIndex() const { return index; }
string Address::getCity() const { return city; }
string Address::getStreet() const { return street; }
