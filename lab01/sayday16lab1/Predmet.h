#ifndef PREDMET_H
#define PREDMET_H
#include <iostream>
#include <string>
using namespace std;

class Predmet {
private:
    string name;
    string semester;
    int grade;
public:
    Predmet();
    Predmet(string n, string sem, int grade);
    Predmet(const Predmet& sub);
    string GetName() const;
    string GetSem() const;
    int GetGrade() const;
    friend istream& operator>>(istream& is, Predmet& pred);
    friend ostream& operator<<(ostream& os, const Predmet& pred);
    Predmet& operator=(const Predmet& pred);
};

#endif
