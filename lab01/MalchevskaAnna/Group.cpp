#include "Group.h"
#include <fstream> 

Group::Group() : name(""), students(nullptr), studentCount(0) {}

Group::Group(string name, Student* students, int studentCount)
    : name(name), students(students), studentCount(studentCount) {}

Group::~Group() {
    delete[] students;
}

void Group::addStudent(const Student& student) {
    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; i++) {
        newStudents[i] = students[i];
    }
    newStudents[studentCount] = student;
    delete[] students;
    students = newStudents;
    studentCount++;
}

void Group::removeStudent(const string& name) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == name) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            break;
        }
    }
}

void Group::printStudents() const {
    for (int i = 0; i < studentCount; i++) {
        cout << students[i] << endl;
    }
}

void Group::searchByName(const string& name) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == name) {
            cout << students[i] << endl;
            return;
        }
    }
    cout << "Student not found" << endl;
}

void Group::searchByGroupName(const string& groupName) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getGroupName() == groupName) {
            cout << students[i] << endl;
        }
    }
}

void Group::searchByAddress(const Address& address) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getAddress().getCity() == address.getCity() &&
            students[i].getAddress().getStreet() == address.getStreet() &&
            students[i].getAddress().getHouseNumber() == address.getHouseNumber()) {
            cout << students[i] << endl;
        }
    }
}

void Group::searchByRecordNumber(const string& recordNumber) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRecordNumber() == recordNumber) {
            cout << students[i] << endl;
        }
    }
}

void Group::saveToFile(const string& students) const {
    ofstream outFile(students);
    if (outFile.is_open()) {
        for (int i = 0; i < studentCount; i++) {
            outFile << students[i] << endl;
        }
        outFile.close();
    }
    else {
        cout << "Error opening file for saving." << endl;
    }
}

void Group::loadFromFile(const string& students) {
    ifstream inFile(students);
    if (inFile.is_open()) {
        Student tempStudent;
        while (inFile >> tempStudent) {
            addStudent(tempStudent);
        }
        inFile.close();
    }
    else {
        cout << "Error opening file for loading." << endl;
    }
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Group Name: " << group.name << endl;
    for (int i = 0; i < group.studentCount; i++) {
        os << group.students[i] << endl;
    }
    return os;
}
