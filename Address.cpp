#include "Address.h"
#include <iostream>

Address::Address(string city, string street, int houseNumber)
    : city(city), street(street), houseNumber(houseNumber) {}

void Address::input() {
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter street: ";
    cin >> street;
    cout << "Enter house number: ";
    cin >> houseNumber;
}
void Address::output() const {
    cout << "City: " << city << ", Street: " << street << ", House number: " << houseNumber << endl;
}
