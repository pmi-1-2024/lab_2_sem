#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string firstName;
    string lastName;
    string group;

    Student(string fName, string lName, string grp);
    void display() const;
};