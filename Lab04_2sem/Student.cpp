#include "Student.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Student& student) {
    os << student.firstName << " " << student.lastName << " " << student.groupName;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    is >> student.firstName >> student.lastName >> student.groupName;
    return is;
}