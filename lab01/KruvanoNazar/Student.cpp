#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(): name("noname"),address(Adresa()),group("nogroup"),zalik(Zalikovka()) {}
Student::Student(string n, Adresa adr, string gr, Zalikovka zal) : name(n), address(adr), group(gr), zalik(zal) {};
string Student::GetName()const { return name; };
Adresa Student::GetAdr()const { return address; }
string Student::GetGroup()const { return group; }
Zalikovka Student::GetZal()const { return zalik; }
istream& operator>>(istream& is, Student& stud) {
    is >> stud.name;
    is >> stud.address;
    is >> stud.group;
    is >> stud.zalik;
    return is;
}
ostream& operator<<(ostream& os, const Student& stud) {
    os << "\nName: " << stud.name;
    os << "\nGroup: " << stud.group;
    os << "\nData of address: " << stud.address;
    os << "\nData of zalikovka: " << stud.zalik;
    return os;
}
bool Student::ToFCriter(string search, int searchnum)const {
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
}

