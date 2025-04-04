#include "Student_Link.h"
#include <iostream>
using namespace std;

Student::Student(string n, int a, string g) : name(n), age(a), group(g) {}

void Student::display() const {
    cout << "Name: " << name << ", Age: " << age << ", Level: " << group << endl;
}

Student_Link::Student_Link(const Student& s) : student(s) {
    next = nullptr;
}