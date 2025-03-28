#include "Group.h"
#include <string>
#include <iostream>
using namespace std;

Group::Group(const string& groupName)
    : name(groupName), studentCount(0), students(nullptr) {}
Group::Group(const Group& other) {
    name = other.name;
    studentCount = other.studentCount;
    students = (studentCount > 0) ? new Student[studentCount] : nullptr;
    for (int i = 0; i < studentCount; ++i) {
        students[i] = other.students[i];
    }
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        delete[] students;
        name = other.name;
        studentCount = other.studentCount;
        students = (studentCount > 0)? new Student[studentCount] : nullptr;
        for (int i = 0; i < studentCount; ++i) {
            students[i] = other.students[i];
        }
    }
    return *this;
}
Group::~Group() {
    delete[] students;
}

string Group::getName() const { return name; }
int Group::getStudentCount() const { return studentCount; }
const Student* Group::getStudents() const { return students; }

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

void Group::removeStudent(const string& studentName) {
    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == studentName) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    if (studentCount == 1) {
        delete[] students;
        students = nullptr;
        studentCount = 0;
        return;
    }

    Student* newStudents = new Student[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; i++) {
        if (i == index) continue;
        newStudents[j++] = students[i];
    }
    delete[] students;
    students = newStudents;
    studentCount--;
}

Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        cerr << "Index goes beyond the students array" << endl;
        exit(EXIT_FAILURE);
    }
    return students[index];
}

Student& Group::operator[](const string& studentName) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getName() == studentName) {
            return students[i];
        }
    }
    cerr << "No student with that name found" << endl;
    exit(EXIT_FAILURE);
}

istream& operator>>(istream& is, Group& group) {
    cout << "Enter the group name: ";
    is >> group.name;
    cout << "Enter the number of students: ";
    is >> group.studentCount;

    if (group.studentCount < 0) {
        cerr << "Student count cannot be negative." << endl;
        exit(EXIT_FAILURE);
    }

    delete[] group.students;
    group.students = (group.studentCount > 0) ? new Student[group.studentCount] : nullptr;

    for (int i = 0; i < group.studentCount; i++) {
        cout << "Enter sudent details " << i + 1 << ": ";
        is >> group.students[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Group: " << group.name << endl;
    os << "Number of students: " << group.studentCount << endl;
    for (int i = 0; i < group.studentCount; i++) {
        os << group.students[i] << endl;
    }
    return os;
}