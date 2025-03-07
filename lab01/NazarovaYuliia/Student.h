#pragma once
#include "Address.h"
#include "Zalikovka.h"
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    string group;
    Address address;
    Zalikovka zalikovka;

public:
    Student();
    Student(const string name, const string groupName, const Address address, const Zalikovka zalikovka);

    string getName() const;
    string getGroupName() const;
    Address getAddress() const;
    Zalikovka getZalikovkaNumber() const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};