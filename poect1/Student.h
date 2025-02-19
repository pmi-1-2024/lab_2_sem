#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"
#include "Zalikovka.h"

class Student {
private:
    string name;
    Address address;
    string group;
    Zalikovka zalikovka;

public:
    Student(string name = "", Address address = Address(), string group = "", Zalikovka zalikovka = Zalikovka());
    string getName() const;
    Address getAddress() const;
    string getGroup() const;
    Zalikovka getZalikovka() const;
    void display() const;
};

#endif



