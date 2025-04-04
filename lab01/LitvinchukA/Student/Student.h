#ifndef STUDENT_H
#define STUDENT_H

#include "Adress.h"
#include "Zalik.h"
#include <string>
using namespace std;

class Student {
    string name;
    Adress adress;
    string group;
    Zalik zalik;

public:
    Student() : name(""), adress(0, "", ""), group(""), zalik(0, 0) {}
    Student(string name, Adress adress, string group, Zalik zalik);
    string getName() const;
    string getGroup() const;
    Adress getAdress() const;
    Zalik getZalik() const;

    friend istream& operator>>(istream& is, Student& student);
    friend ostream& operator<<(ostream& os, const Student& student);
};

#endif
