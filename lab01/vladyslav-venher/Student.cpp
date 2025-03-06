#include "Student.h"
using namespace std;

Student::Student() : name(""), group("") {}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.name << "\n" << student.address << "\n" << student.group << "\n" << student.zalikovka;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    getline(is, student.name);
    is >> student.address;
    is.ignore();
    getline(is, student.group);
    is >> student.zalikovka;
    return is;
}