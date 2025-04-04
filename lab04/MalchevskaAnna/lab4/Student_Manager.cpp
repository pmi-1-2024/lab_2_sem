#include "Student_Manager.h"

void Student_Manager::addStudent(const Student& s) {
    studentsList.addStudent(s);
    cout << "Student added successfully!" << endl;
}

void Student_Manager::removeStudent(const string& name) {
    if (studentsList.empty()) {
        cout << "No students in the list. Nothing to remove." << endl;
        return;
    }
    if (studentsList.removeStudentByName(name)) {
        cout << "Student " << name << " removed successfully." << endl;
    }
    else {
        cout << "Student " << name << " not found." << endl;
    }
}

void Student_Manager::findStudentByName(const string& name) const {
    if (studentsList.empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    Student_Link* studentLink = studentsList.findStudentByName(name);
    if (studentLink) {
        cout << "Student found: ";
        studentLink->data.print();
    }
    else {
        cout << "Student " << name << " not found." << endl;
    }
}

void Student_Manager::findStudentByGroup(const string& group) const {
    if (studentsList.empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    Student_Link* studentLink = studentsList.findStudentByGroup(group);
    if (studentLink) {
        cout << "Student found: ";
        studentLink->data.print();
    }
    else {
        cout << "No students found in group " << group << "." << endl;
    }
}

void Student_Manager::findStudentByAddress(const string& address) const {
    if (studentsList.empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    Student_Link* studentLink = studentsList.findStudentByAddress(address);
    if (studentLink) {
        cout << "Student found: ";
        studentLink->data.print();
    }
    else {
        cout << "No students found with address " << address << "." << endl;
    }
}

void Student_Manager::updateStudent(const string& name, const Student& newData) {
    if (studentsList.empty()) {
        cout << "No students in the list. Nothing to update." << endl;
        return;
    }
    Student_Link* studentLink = studentsList.findStudentByName(name);
    if (studentLink) {
        studentLink->data = newData;
        cout << "Student " << name << " updated successfully." << endl;
    }
    else {
        cout << "Student " << name << " not found." << endl;
    }
}

void Student_Manager::printAllStudents() const {
    if (studentsList.empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    studentsList.printAll();
}