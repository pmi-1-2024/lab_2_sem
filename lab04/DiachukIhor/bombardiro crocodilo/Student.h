#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;

    Student(string nm = "", int i = 0) : name(nm), id(i) {}

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "��'�: " << student.name << "\nID: " << student.id;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student) {
        cout << "������ ��'� ��������: ";
        is >> student.name;
        cout << "������ ID ��������: ";
        is >> student.id;
        return is;
    }
};

#endif 
