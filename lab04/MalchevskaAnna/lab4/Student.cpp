#include "Student.h"

Student::Student(const string& n, int a, const string& m,
    const string& addr, const string& grp)
    : name(n), age(a), major(m), address(addr), group(grp) {}

void Student::print() const {
    cout << "Name: " << name << ", Age: " << age << ", Major: " << major
        << ", Address: " << address << ", Group: " << group << endl;

    istream& operator>>(istream& is, Student& s) {
    cout << "Enter name: ";
    getline(is, s.name);
    cout << "Enter age: ";
    is >> s.age;
    is.ignore(); 
    cout << "Enter major: ";
    getline(is, s.major);
    cout << "Enter address: ";
    getline(is, s.address);
    cout << "Enter group: ";
    getline(is, s.group);
    return is;
}
