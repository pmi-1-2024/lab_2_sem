#include "Student.h"
Student::Student(string n, Address a, string g, RecordBook rb) : name(n), address(a), group(g), recordBook(rb) {}
void Student::display() const {
    cout << "Студент: " << name << endl;
    address.display();
    cout << "Група: " << group << endl;
    recordBook.display();
}