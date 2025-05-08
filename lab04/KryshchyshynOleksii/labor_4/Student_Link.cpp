#include "Student_Link.h"
#include <iostream>
using namespace std;

Student::Student(string n, int a, string g) : name(n), age(a), group(g) {}

void Student::display() const {
   cout << "Name: " << name << ", Age: " << age << ", Level: " << group << endl;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.name << " " << student.age << " " << student.group;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    is >> student.name >> student.age >> student.group;
    return is;
}


Student_Link::Student_Link(const Student& s) : student(s) {
    next = nullptr;
}

void Student::input() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter level/group: ";
    cin >> group;
}