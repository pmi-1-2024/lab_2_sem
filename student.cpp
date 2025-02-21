#include "Student.h"
Student::Student(string n, Address a, string g, RecordBook rb) : name(n), address(a), group(g), recordBook(rb) {}
void Student::display() const {
    cout << "Student: " << name << endl;
    address.display();
    cout << "Group: " << group << endl;
    recordBook.display();
}
