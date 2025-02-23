#include "Student.h"
#include <string>  

Student::Student() : name(""), address(Address()), groupName(""), recordBook(RecordBook()) {}

Student::Student(string name, Address address, string groupName, RecordBook recordBook)
    : name(name), address(address), groupName(groupName), recordBook(recordBook) {}

string Student::getName() const { return name; }
string Student::getGroupName() const { return groupName; }
string Student::getRecordNumber() const {
    return to_string(recordBook.getNumber());
}
Address Student::getAddress() const { return address; }

ostream& operator<<(ostream& os, const Student& student) {
    os << "Name: " << student.name << "\nGroup: " << student.groupName << "\n" << student.address
        << "\n" << student.recordBook;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Enter student name: ";
    is >> student.name;
    cout << "Enter group name: ";
    is >> student.groupName;
    is >> student.address;
    is >> student.recordBook;
    return is;
}