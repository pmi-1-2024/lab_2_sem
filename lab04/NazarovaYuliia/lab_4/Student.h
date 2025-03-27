#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    string group;

public:

    Student() : firstName(""), lastName(""), group("") {}
    Student(string fName, string lName, string grp);
    void display() const;

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getGroup() const { return group; }

    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setGroup(string grp) { group = grp; }

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};