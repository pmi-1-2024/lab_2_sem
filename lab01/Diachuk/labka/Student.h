#pragma once
#include <string>

using namespace std;

class Student {
public:
    string name;
    string group;
    string subject;
    string residence;
    double grade;
    string postal_code;

    Student();
    Student(string name, string group, string subject, string residence, double grade, string postal_code);

    void print() const;
};
