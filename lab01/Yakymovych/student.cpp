#include "Student.h"

Student::Student() : firstName(""), lastName(""), groupName("") {}

Student::Student(const string& firstName, const string& lastName, const Address& address, const string& groupName, const RecordBook& recordBook)
    : firstName(firstName), lastName(lastName), address(address), groupName(groupName), recordBook(recordBook) {}

string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getGroupName() const { return groupName; }
Address Student::getAddress() const { return address; }
RecordBook Student::getRecordBook() const { return recordBook; }

ostream& operator<<(ostream& os, const Student& student) {
    os << student.firstName << " " << student.lastName << " " << student.address << " " << student.groupName << " " << student.recordBook.getNumber();
    return os;
}

istream& operator>>(istream& is, Student& student) {
    is >> student.firstName >> student.lastName >> student.address >> student.groupName >> student.recordBook;
    return is;
}
