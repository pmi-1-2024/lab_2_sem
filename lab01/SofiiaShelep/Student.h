#pragma once
#include "Address.h"
#include "Zalikovka.h"

class Student
{
private:
    string name;
    string group;
    Address address;
    Zalikovka zalikovka;

public:
    Student();
    Student(string n, string g, Address a, Zalikovka z);

    void setName(string n);
    void setGroup(string g);
    void setAddress(Address a);
    void setZalikovka(Zalikovka z);

    string getName() const;
    string getGroup() const;
    Address getAddress() const;
    Zalikovka getZalikovka() const;

    void show() const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};