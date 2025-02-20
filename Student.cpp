#include "Student.h"
#include <iostream>

Student::Student(string name, string groupName, Address address, RecordBook recordBook)
    : name(name), groupName(groupName), address(address), recordBook(recordBook) {}

void Student::input() {
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter group name: ";
    cin >> groupName;
    address.input();
    recordBook.input();
}
void Student::output() const {
    cout << "Student: " << name << ", Group: " << groupName << endl;
    address.output();
    recordBook.output();
}
