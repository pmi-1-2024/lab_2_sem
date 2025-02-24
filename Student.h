#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Address.h"
#include "Zalikovka.h"
using namespace std;
class Student {
private:
    string name;
    Adress adress;
    string group;
    Zalikovka zalik;
public:
    Student(string name = "", Adress adress = Adress(), string group = "", Zalikovka zalik = Zalikovka());
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

};

#endif
