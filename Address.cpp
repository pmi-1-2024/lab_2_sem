#include "Address.h"
#include <iostream>

Address::Address() : city(""), street(""), houseNumber(0), index(0) {}

Address::Address(string city, string street, int houseNumber, int index)
    : city(city), street(street), houseNumber(houseNumber), index(index) {
}

void Address::input() {
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter street: ";
    cin >> street;
    cout << "Enter house number: ";
    cin >> houseNumber;
    cout << "Enter index: ";
    cin >> index;
}

void Address::output() const {
    cout << "City: " << city << ", Street: " << street << ", House number: " << houseNumber << ", Index: " << index << endl;
}