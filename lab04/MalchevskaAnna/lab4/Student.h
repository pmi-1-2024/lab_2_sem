#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;
    string major;
    string address;  
    string group;    
    Student(const string& n = "", int a = 0, const string& m = "",
        const string& addr = "", const string& grp = "");
    void print() const;
};

