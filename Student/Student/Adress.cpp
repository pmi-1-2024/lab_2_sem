#include "Adress.h"
#include <iostream>
using namespace std;

Adress::Adress(unsigned index, string city, string house) :
    index(index), city(city), house(house) {
}

void Adress::print() {
    cout << "\tАдреса: Індекс = " << index << ", Місто = " << city << ", Будинок = " << house << "." << endl;
}

unsigned Adress::getIndex() { return index; }
string Adress::getCity() { return city; }
string Adress::getHouse() { return house; }
