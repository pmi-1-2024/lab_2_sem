#ifndef STUDENT_H
#define STUDENT_H
#include "Predmet.h"
#include "Zalikovka.h"
#include "Adresa.h"
#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    string name;
    Adresa address;
    string group;
    Zalikovka zalik;
public:
    Student();
    Student(string n, Adresa adr, string gr, Zalikovka zal);
    string GetName()const;
    Adresa GetAdr()const;
    string GetGroup()const;
    Zalikovka GetZal()const;
    bool ToFCriter(string search,int searchnum)const;
    friend istream& operator>>(istream& is, Student& stud);
    friend ostream& operator<<(ostream& os, const Student& stud);
};

#endif
