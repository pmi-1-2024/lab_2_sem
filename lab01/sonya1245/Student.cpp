#include "Student.h"

Student::Student() : name(""), group("") {}

istream& operator>>(istream& in, Student& student) {
    cout << "Enter student's name: ";
    in >> student.name;
    in >> student.address;
    cout << "Enter group name: ";
    in >> student.group;
    in >> student.recordBook;
    return in;
}

ostream& operator<<(ostream& out, const Student& student) {
    cout << "\033[32m";
    out << "Name: " << student.name << "\n";
    out << student.address << "\n";
    out << "Group: " << student.group << "\n";
    out << student.recordBook;
    cout << "\033[0m";
    return out;
}

const string& Student::getName() const {
    return name;
}

const string& Student::getGroup() const {
    return group;
}

const string& Student::getRecordNumber() const {
    return recordBook.getRecordNumber();
}

const Address& Student::getAddress() const {
    return address;
}

const RecordBook& Student::getRecordBook() const {
    return recordBook;
}