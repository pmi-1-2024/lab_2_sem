#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Student {
public:
    int id;
    std::string name;
    int age;
    std::string group;

    Student();
    friend std::ostream& operator<<(std::ostream& out, const Student& s);
    friend std::istream& operator>>(std::istream& in, Student& s);
};
