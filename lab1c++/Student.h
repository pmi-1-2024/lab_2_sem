#pragma once
#include "Address.h"
#include "Zalikovka.h"
class Student {
private:
    string name, group;
    Address address;
    Zalikovka zalik;
public:
    Student();
    Student(string n, string g, Address a, Zalikovka z) ;
    string getName() const;
    string getGroup() const;
    string getId() const;
    string getAddress() const;
    void display() const;
    void read(istream& is);
    friend istream& operator>>(istream& is, Student& s);
};
