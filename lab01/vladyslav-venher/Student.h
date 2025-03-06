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
    Student(string n, Address a, string g, Zalikovka z);
    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);
};