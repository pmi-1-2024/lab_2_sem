#include "Student.h"
using namespace std;
Student::Student(string name, Adress adress, string group, Zalikovka zalik)
    : name(name), adress(adress), group(group), zalik(zalik) {}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Student: " << student.name << "\n" << student.adress << "\nGroup: " << student.group << "\n" << student.zalik;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    is >> student.name >> student.adress >> student.group >> student.zalik;
    return is;
}