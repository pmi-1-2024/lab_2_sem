#pragma once
#include <iostream>
#include <string>

using namespace std;

class Subject {
private:
    string name;
    int semester;
    double grade;
public:
    Subject();
    Subject(string n, int s, double g);
    string getName() const;
    int getSemester() const;

    void setAll(string _name, int _semester, double _grade);

    void display() const;
    void read(istream& is);
    friend istream& operator>>(istream& is, Subject& s);
    /*friend ostream& operator<<(ostream& os, Subject& s);*/
};

