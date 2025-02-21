#ifndef STUDENT_H
#define STUDENT_H
#include "Predmet.h"
#include "Zalikovka.h"
#include "Adresa.h"
#include <iostream>
#include <string>
using namespace std;


class Student {
public:
    string name;
    Adresa address;
    string group;
    Zalikovka zalik;
    Student();
    Student(string n, Adresa adr, string gr, Zalikovka zal);
    void input();
    void display();
    string GetName()const;
    Adresa GetAdr()const;
    string GetGroup()const;
    Zalikovka GetZal()const;
    bool ToFCriter(string search,int searchnum);
};

#endif
