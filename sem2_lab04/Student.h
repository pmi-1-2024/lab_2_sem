#pragma once

#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    string groupName;

public:
    Student() : firstName(""), lastName(""), groupName("") {}
    Student(const string& firstName, const string& lastName, const string& groupName)
        : firstName(firstName), lastName(lastName), groupName(groupName) {}

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getGroupName() const { return groupName; }

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};


