#include "Student.h"
#include <iostream>

Student::Student(string name, Address address, string group, Zalikovka zalikovka)
    : name(name), address(address), group(group), zalikovka(zalikovka) {}

string Student::getName() const { return name; }
Address Student::getAddress() const { return address; }
string Student::getGroup() const { return group; }
Zalikovka Student::getZalikovka() const { return zalikovka; }

void Student::display() const {
    cout << "Name: " << name << endl;
    cout << "Group: " << group << endl;
    cout << "Address: " << address.getCity() << ", " << address.getStreet() << " (" << address.getPostIndex() << ")" << endl;
    for (int i = 0; i < zalikovka.getSubjectCount(); i++) {
        cout << "Subject: " << zalikovka.getSubjects()[i].getName()
            << ", Semester: " << zalikovka.getSubjects()[i].getSemester()
            << ", Grade: " << zalikovka.getSubjects()[i].getGrade() << endl;
    }
}



