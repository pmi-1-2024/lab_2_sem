#include "Student.h"
#include <iostream>

Student::Student() : name(""), group(""), address(), subject1(), subject2() {}

Student::Student(string n, string g, Address a, Subject s1, Subject s2)
    : name(n), group(g), address(a), subject1(s1), subject2(s2) {
}

void Student::setName(string n) { name = n; }
void Student::setGroup(string g) { group = g; }
void Student::setAddress(Address a) { address = a; }
void Student::setSubjects(Subject s1, Subject s2) { subject1 = s1; subject2 = s2; }

string Student::getName() const { return name; }
string Student::getGroup() const { return group; }
Address Student::getAddress() const { return address; }
Subject Student::getSubject1() const { return subject1; }
Subject Student::getSubject2() const { return subject2; }

ostream& operator<<(ostream& os, const Student& student)
{
    os << student.name << " " << student.group << " " << student.address << " " << student.subject1 << " " << student.subject2;
    return os;
}

istream& operator>>(istream& is, Student& student)
{
    is >> student.name >> student.group >> student.address >> student.subject1 >> student.subject2;
    return is;
}

