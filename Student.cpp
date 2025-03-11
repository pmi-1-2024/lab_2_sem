#include "Student.h"

ostream& operator<<(ostream& out, const Student& student) {
    out << "�������: " << student.name << endl;
    out << student.address << endl;
    out << "�����: " << student.group << endl;
    out << student.recordBook;
    return out;
}

istream& operator>>(istream& in, Student& student) {
    cout << "������ ��'� ��������: ";
    in >> student.name;
    cout << "������ �����: ";
    in >> student.group;
    in >> student.address;
    in >> student.recordBook;
    return in;
}
