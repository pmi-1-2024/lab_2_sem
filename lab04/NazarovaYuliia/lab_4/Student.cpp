#include "Student.h"

Student::Student(string fName, string lName, string grp) : firstName(fName), lastName(lName), group(grp) {}
void Student::display() const {
    cout << firstName << " " << lastName << " (" << group << ")" << endl;
}

istream& operator>>(istream& is, Student& s) {
    cout << "Enter first name: ";
    is >> s.firstName;
    cout << "Enter last name: ";
    is >> s.lastName;
    cout << "Enter group: ";
    is >> s.group;
    return is;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << "First name: " << s.firstName << ", Last name: " << s.lastName
        << ", Group: " << s.group;
    return os;
}