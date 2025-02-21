#include "Student.h"
#include <iostream>

Student::Student() {}

void Student::input() {
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter group: ";
    cin >> group;
    cout << "Enter address details:" << endl;
    address.input();
    cout << "Enter zalikovka details:" << endl;
    zalikovka.input();
}

void Student::output() const {
    cout << "Student: " << name << ", Group: " << group << endl;
    address.output();
    zalikovka.output();
}