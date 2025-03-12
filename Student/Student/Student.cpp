#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, Adress adress, string group, Zalik zalik) :
    name(name), adress(adress), group(group), zalik(zalik) {
}

string Student::getName() const { return name; }
string Student::getGroup() const { return group; }
Adress Student::getAdress() const { return adress; }
Zalik Student::getZalik() const { return zalik; }

istream& operator>>(istream& is, Student& student) {
    is >> ws;
    getline(is, student.name);
    is >> student.adress;
    is >> ws;
    getline(is, student.group);
    is >> student.zalik;
    return is;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "²ì'ÿ: " << student.name << ", Ãğóïà: " << student.group << endl;
    os << student.adress << endl;
    os << student.zalik << endl;
    return os;
}
