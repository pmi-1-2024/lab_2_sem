#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int age = 0;  
    double grade = 0.0; 

    friend ostream& operator<<(ostream& os, const Student& s) {
        return os << "[" << s.name << ", " << s.age << " Років, оцінка: " << s.grade << "]";
    }
};

#endif