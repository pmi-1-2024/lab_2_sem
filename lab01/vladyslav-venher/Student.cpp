#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), group("") {}

void Student::print() const {
    cout << "�������: " << name << endl;
    address.print();
    cout << "�����: " << group << endl;
    zalikovka.output();
}