#include "Address.h"
#include <iostream>
using namespace std;

Address::Address() : zipcode(0), city(""), street("") {}

void Address::setAddress(int code, const string& c, const string& s) {
    zipcode = code;
    city = c;
    street = s;
}

void Address::print() const {
    cout << "Адреса: " << zipcode << ", " << city << ", " << street << endl;
}