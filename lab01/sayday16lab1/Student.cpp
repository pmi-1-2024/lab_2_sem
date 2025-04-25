#include "Student.h"
#include <iostream>
#include <string>

// ����������� �� �������������
Student::Student() {
    name = "";
    group = "";
}

// ����������� � �����������
Student::Student(string n, Adresa adr, string gr, Zalikovka zal) {
    name = n;
    address = adr;
    group = gr;
    zalik = zal;
}

// ������ ��� ���� ��������
string Student::GetName() const {
    return name;
}

// ������ ��� ������ ��������
Adresa Student::GetAdr() const {
    return address;
}

// ������ ��� ����� ��������
string Student::GetGroup() const {
    return group;
}

// ������ ��� �������� ��������
Zalikovka Student::GetZal() const {
    return zalik;
}

// ����� ��� ������ �� �������
bool Student::ToFCriter(string search, int searchnum) const {
    switch (searchnum) {
    case 1: // ����� �� ����
        return name.find(search) != string::npos;
    case 2: // ����� �� ����
        return group.find(search) != string::npos;
    case 3: // ����� �� �����
        return address.GetCity().find(search) != string::npos || address.GetStreet().find(search) != string::npos;
    case 4: // ����� �� ��������
        return zalik.GetNumber().find(search) != string::npos;
    default:
        return false;
    }
}

// �������� ��������
istream& operator>>(istream& is, Student& stud) {
    cout << "Enter student's name: ";
    is >> stud.name;

    cout << "Enter student's group: ";
    is >> stud.group;

    cout << "Enter student's address (city, street, postal code): ";
    is >> stud.address;

    cout << "Enter student's record book details: ";
    is >> stud.zalik;

    return is;
}

// �������� ���������
ostream& operator<<(ostream& os, const Student& stud) {
    os << "Student's name: " << stud.name << endl;
    os << "Group: " << stud.group << endl;
    os << "Address: " << stud.address << endl;
    os << "Record Book: " << stud.zalik << endl;
    return os;
}
