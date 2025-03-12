#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() : name(""), group(""), subject(""), residence(""), grade(0.0), postal_code("") {}

Student::Student(string name, string group, string subject, string residence, double grade, string postal_code)
    : name(name), group(group), subject(subject), residence(residence), grade(grade), postal_code(postal_code) {
}

void Student::print() const {
    cout << "��'�: " << name
        << ", �����: " << group
        << ", �������: " << subject
        << ", ������: " << residence
        << ", ������: " << grade
        << ", �������� ������: " << postal_code
        << endl;
}
