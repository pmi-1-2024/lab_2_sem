#include "Student.h"

Student::Student(const string& n, int a, const string& m,
    const string& addr, const string& grp)
    : name(n), age(a), major(m), address(addr), group(grp) {}

void Student::print() const {
    cout << "Name: " << name << ", Age: " << age << ", Major: " << major
        << ", Address: " << address << ", Group: " << group << endl;
}