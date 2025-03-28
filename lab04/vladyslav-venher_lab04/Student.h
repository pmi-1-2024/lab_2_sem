#pragma once
#include "List.h"
#include <iostream>
using namespace std;


struct Student {
    string firstName;
    string lastName;
    double gpa;
    Student(string fn = "", string ln = "", double g = 0.0) : firstName(fn), lastName(ln), gpa(g) {}

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

struct Student_Node : Node {
    Student info;
    Student_Node(const Student& student) : info(student) {}
};


ostream& operator<<(ostream& os, const Student& student) {
    os << "First Name: " << student.firstName
        << ", Last Name: " << student.lastName
        << ", GPA: " << student.gpa;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Enter first name: ";
    is >> student.firstName;
    cout << "Enter last name: ";
    is >> student.lastName;
    cout << "Enter GPA: ";
    is >> student.gpa;
    return is;
}