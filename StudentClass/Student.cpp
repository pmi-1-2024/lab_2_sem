#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), group("") {}

void Student::input() {
    cout << "Введіть ім'я студента: ";
    cin >> name;
    cout << "Введіть групу: ";
    cin >> group;
    cout << "Введення адреси:" << endl;
    address.input();
    cout << "Введення заліковки:" << endl;
    zalik.input();
}

void Student::display() {
    cout << "Студент: " << name << ", Група: " << group << endl;
    address.display();
    zalik.display();
}
Student::Student(string n, Adresa adr, string gr, Zalikovka zal) : name(n), address(adr), group(gr), zalik(zal) {};
string Student::GetName()const { return name; };
Adresa Student::GetAdr()const { return address; }
string Student::GetGroup()const { return group; }
Zalikovka Student::GetZal()const { return zalik; }
bool Student::ToFCriter(string search, int searchnum) {
    switch (searchnum) {
    case 1:
        return name == search;
    case 2:
        return address.GetCity() == search;
    case 3:
        return group == search;
    case 4:
        return zalik.GetNumber() == search;
    case 5:
        return zalik.hasSub(search);
    case 6:
        return zalik.hasSem(search);

    
    default:
        return false;
}

