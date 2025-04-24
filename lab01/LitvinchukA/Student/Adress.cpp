#include "Adress.h"
#include <iostream>
using namespace std;

Adress::Adress(unsigned index, string city, string house) :
    index(index), city(city), house(house) {
}

unsigned Adress::getIndex() { return index; }
string Adress::getCity() { return city; }
string Adress::getHouse() { return house; }

istream& operator>>(istream& is, Adress& adress) {
    is >> adress.index >> ws;
    getline(is, adress.city);
    getline(is, adress.house);
    return is;
}

ostream& operator<<(ostream& os, const Adress& adress) {
    os << "²íäåêñ: " << adress.index << ", Ì³ñòî: " << adress.city << ", Ä³ì: " << adress.house << endl;
    return os;
}
