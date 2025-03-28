#include "Student.h"
#include <iostream>

Student::Student() : name(""), group(""), address(), zalikovka() {}
Student::Student(const string& name, const string& groupName, const Address& address, const Zalikovka& zalikovka)
    : name(name), group(groupName), address(address), zalikovka(zalikovka) {}

string Student::getName() const { return name; }
string Student::getGroupName() const { return group; }
Zalikovka Student::getZalikovkaNumber() const { return zalikovka; }
Address Student::getAddress() const { return address; }

ostream& operator<<(ostream& os, const Student& student) {
    os << "Name: " << student.name << "\n"
        << "Group: " << student.group << "\n"
        << "Address: " << student.address << "\n"
        << "Zalikovka: " << student.zalikovka << "\n";
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Enter student name: ";
    is.ignore();
    getline(is, student.name);

    cout << "Enter group name: ";
    getline(is, student.group);

    cout << "Enter address: ";
    is >> student.address;

    cout << "Enter zalikovka: ";
    is >> student.zalikovka;
    return is;
}