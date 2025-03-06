#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Group {
private:
    string name;
    Student* students;
    int studentCount;
public:
    Group();
    Group(const string& name, int count);
    Group(const Group& other);
    Group& operator=(const Group& other);
    ~Group();
    Student& operator[](int index);
    friend ostream& operator<<(ostream& os, const Group& g);
    friend istream& operator>>(istream& is, Group& g);
};
