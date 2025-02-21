#include "Adresa.h"
#include <iostream>
using namespace std;

Adresa::Adresa() : index(""), city(""), street("") {}
Adresa::Adresa(string ind, string cit, string str): index(ind) , city(cit), street(str){}

void Adresa::input() {
    cout << "������ ������: ";
    cin >> index;
    cout << "������ ����: ";
    cin >> city;
    cout << "������ ������: ";
    cin >> street;
 
}

void Adresa::display()const {
    cout << "������: " << index << ", " << city << ", " << street << " " << endl;
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

