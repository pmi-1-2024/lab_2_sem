#include "Group.h"
#include <iostream>
#include <fstream>
using namespace std;

Group::Group(string name) : name(name), students(nullptr), studentsCount(0) {}

Group::Group(const Group& other) : name(other.name), studentsCount(other.studentsCount) {
    students = new Student[studentsCount];
    for (unsigned i = 0; i < studentsCount; ++i) {
        students[i] = other.students[i];
    }
}

Group& Group::operator=(const Group& other) {
    if (this == &other) return *this;

    if (students != nullptr) {
        delete[] students;
    }

    name = other.name;
    studentsCount = other.studentsCount;
    students = new Student[studentsCount];
    for (unsigned i = 0; i < studentsCount; ++i) {
        students[i] = other.students[i];
    }

    return *this;
}

Group::~Group() {
    if (students != nullptr) {
        delete[] students;
    }
}

void Group::addStudent(const Student& student) {
    Student* newStudents = new Student[studentsCount + 1];
    for (unsigned i = 0; i < studentsCount; ++i) {
        newStudents[i] = students[i];
    }
    newStudents[studentsCount] = student;
    delete[] students;
    students = newStudents;
    ++studentsCount;
}

string Group::getName() const {
    return name;
}

unsigned Group::getStudentsCount() const {
    return studentsCount;
}

Student* Group::getStudents() const {
    return students;
}

istream& operator>>(istream& is, Group& group) {
    is >> ws;
    getline(is, group.name);
    is >> group.studentsCount;
    group.students = new Student[group.studentsCount];
    for (unsigned i = 0; i < group.studentsCount; ++i) {
        is >> group.students[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "�����: " << group.name << ", �-��� ��������: " << group.studentsCount << endl;
    for (unsigned i = 0; i < group.studentsCount; ++i) os << group.students[i] << endl;
    return os;
}
