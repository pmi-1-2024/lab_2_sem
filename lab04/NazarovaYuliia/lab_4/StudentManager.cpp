#include "StudentManager.h"

void Student_Manager::addStudent(string fName, string lName, string grp) {
    students.push(Student(fName, lName, grp));
}

void Student_Manager::removeStudent(string fName, string lName) {
    students.remove(fName, lName);
}

void Student_Manager::findStudent(const string& fName, const string& lName, const string& grp) {
    Student_Link* found = students.find(Student(fName, lName, grp));
    if (found) {
        cout << "Student found: ";
        found->student.display();
    }
    else {
        cout << "No student found." << endl;
    }
}

void Student_Manager::displayAll() {
    students.display();
}

void Student_Manager::insertAfter(const Student& newStudent, const string& afterFName, const string& afterLName) {
    Student_Link* after = students.find(Student(afterFName, afterLName, ""));
    if (after) {
        students.insert(newStudent, after);
    }
    else {
        cout << "Student to insert not found!" << endl;
    }
}

Student Student_Manager::getTopStudent() const {
    return students.top();
}