#pragma once
#include <iostream>
#include <string>
using namespace std;

class Subject {
private:
    string name;
    int semester;
    int grade;
public:
    Subject();
    Subject(string n, int sem, int g);
    friend ostream& operator<<(ostream& os, const Subject& s);
    friend istream& operator>>(istream& is, Subject& s);
};