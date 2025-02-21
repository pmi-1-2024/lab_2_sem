#ifndef PREDMET_H
#define PREDMET_H
#include <iostream>
#include <string>
using namespace std;

class Predmet {
public:
    string name;
    string semester;
    int grade;
    Predmet();
    Predmet(string n, string sem,int grade);
    void input();
    void display();
    string GetName() const;
    string GetSem() const;
    int GetGrade() const;
};

#endif
