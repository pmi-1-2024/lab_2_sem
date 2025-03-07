#pragma once
#include "Address.h"
#include "Subject.h"

class Student
{
private:
    string name;
    string group;
    Address address;
    Subject subject1, subject2;

public:
    Student();
    Student(string n, string g, Address a, Subject s1, Subject s2);

    void setName(string n);
    void setGroup(string g);
    void setAddress(Address a);
    void setSubjects(Subject s1, Subject s2);

    string getName() const;
    string getGroup() const;
    Address getAddress() const;
    Subject getSubject1() const;
    Subject getSubject2() const;

    void show() const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};