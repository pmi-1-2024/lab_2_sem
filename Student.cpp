#include "Student.h"
#include <iostream>
#include <string>

// Конструктор за замовчуванням
Student::Student() {
    name = "";
    group = "";
}

// Конструктор з параметрами
Student::Student(string n, Adresa adr, string gr, Zalikovka zal) {
    name = n;
    address = adr;
    group = gr;
    zalik = zal;
}

// Геттер для імені студента
string Student::GetName() const {
    return name;
}

// Геттер для адреси студента
Adresa Student::GetAdr() const {
    return address;
}

// Геттер для групи студента
string Student::GetGroup() const {
    return group;
}

// Геттер для заліковки студента
Zalikovka Student::GetZal() const {
    return zalik;
}

// Метод для пошуку по критерію
bool Student::ToFCriter(string search, int searchnum) const {
    switch (searchnum) {
    case 1: // Пошук по імені
        return name.find(search) != string::npos;
    case 2: // Пошук по групі
        return group.find(search) != string::npos;
    case 3: // Пошук по адресі
        return address.GetCity().find(search) != string::npos || address.GetStreet().find(search) != string::npos;
    case 4: // Пошук по заліковці
        return zalik.GetNumber().find(search) != string::npos;
    default:
        return false;
    }
}

// Оператор введення
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

// Оператор виведення
ostream& operator<<(ostream& os, const Student& stud) {
    os << "Student's name: " << stud.name << endl;
    os << "Group: " << stud.group << endl;
    os << "Address: " << stud.address << endl;
    os << "Record Book: " << stud.zalik << endl;
    return os;
}
