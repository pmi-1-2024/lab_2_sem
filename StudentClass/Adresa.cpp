#include "Adresa.h"
#include <iostream>
using namespace std;

Adresa::Adresa(){}
Adresa::Adresa(string ind, string cit, string str): index(ind) , city(cit), street(str){}

string Adresa::GetCity() const {
    return city;
}
string Adresa::GetIndex()const {
    return index;
}
string Adresa::GetStreet()const {
    return street;
}

istream& operator>>(istream& is, Adresa& adr)
{
    cout << "\nEnter index: ";
    is >> adr.index;
    cout << "\nEnter city: ";
    is >> adr.city;
    cout << "Enter street: ";
    is >> adr.street;
    return is;
}
ostream& operator<<(ostream& os, const Adresa& adr) {
    os << "\nCity: " << adr.city;
    os << "\nIndex: " << adr.index;
    os << "\nStreet: " << adr.street;
    return os;
}
