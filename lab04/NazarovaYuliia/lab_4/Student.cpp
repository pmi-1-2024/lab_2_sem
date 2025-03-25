#include "Student.h"

Student::Student(string fName, string lName, string grp) : firstName(fName), lastName(lName), group(grp) {}
void Student::display() const {
    cout << firstName << " " << lastName << " (" << group << ")" << endl;
}