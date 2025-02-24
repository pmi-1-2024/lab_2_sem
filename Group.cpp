#include "Group.h"
using namespace std;

Group::Group(string name, int studentCount) : name(name), studentCount(studentCount) {
    students = new Student[studentCount];
}

Group::~Group() {
    delete[] students;
}

void Group::addStudent(const Student& student) {
    Student* temp = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; ++i) {
        temp[i] = students[i];
    }
    temp[studentCount] = student;
    delete[] students;
    students = temp;
    ++studentCount;
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Group: " << group.name << "\n";
    for (int i = 0; i < group.studentCount; ++i) {
        os << group.students[i] << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Group& group) {
    is >> group.name >> group.studentCount;
    delete[] group.students;
    group.students = new Student[group.studentCount];
    for (int i = 0; i < group.studentCount; ++i) {
        is >> group.students[i];
    }
    return is;
}