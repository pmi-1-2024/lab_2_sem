#include "StudentManager.h"

void Student_Manager::addStudent(string fName, string lName, string grp) {
    students.add(new Student_Link(Student(fName, lName, grp)));
}

void Student_Manager::removeStudent(string fName, string lName) {
    students.remove(fName, lName);
}

void Student_Manager::findStudentByName(string fName) {
    Student_Link* found = students.findByName(fName);
    if (found) found->student.display();
    else cout << "Student not found." << endl;
}

void Student_Manager::findStudentByLastName(string lName) {
    Student_Link* found = students.findByLastName(lName);
    if (found) found->student.display();
    else cout << "Student not found." << endl;
}

void Student_Manager::findStudentsByGroup(string grp) {
    students.findByGroup(grp);
}

void Student_Manager::displayAll() {
    students.display();
}
