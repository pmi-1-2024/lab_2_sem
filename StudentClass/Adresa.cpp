#include "Adresa.h"
#include <iostream>
using namespace std;

Adresa::Adresa() : index(""), city(""), street("") {}
Adresa::Adresa(string ind, string cit, string str): index(ind) , city(cit), street(str){}

void Adresa::input() {
    cout << "¬вед≥ть ≥ндекс: ";
    cin >> index;
    cout << "¬вед≥ть м≥сто: ";
    cin >> city;
    cout << "¬вед≥ть вулицю: ";
    cin >> street;
 
}

void Adresa::display()const {
    cout << "јдреса: " << index << ", " << city << ", " << street << " " << endl;
}

string Adresa::GetCity() const {
    return city;
}
string Adresa::GetIndex()const {
    return index;
}
string Adresa::GetStreet()const {
    return street;
}

