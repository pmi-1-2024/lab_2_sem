#include "Student.h"

ostream& operator<<(ostream& out, const Student& student) {
    out << "Студент: " << student.name << endl;
    out << student.address << endl;
    out << "Група: " << student.group << endl;
    out << student.recordBook;
    return out;
}

istream& operator>>(istream& in, Student& student) {
    cout << "Введіть ім'я студента: ";
    in >> student.name;
    cout << "Введіть групу: ";
    in >> student.group;
    in >> student.address;
    in >> student.recordBook;
    return in;
}
