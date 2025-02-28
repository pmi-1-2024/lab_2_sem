#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), group("") {}

void Student::print() const {
    cout << "Студент: " << name << endl;
    address.print();
    cout << "Група: " << group << endl;
    zalikovka.output();
}