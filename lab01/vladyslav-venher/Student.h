#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include "Zalikovka.h"
using namespace std;

class Student {
private:
    string name;
    Address address;
    string group;
    Zalikovka zalikovka;
public:
    Student();
    Student(string name, Address address, string group, Zalikovka zalikovka);

    string getName() const;
    Address getAddress() const;
    string getGroup() const;
    Zalikovka getZalikovka() const;

    bool match(string searchValue, int searchType) const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};