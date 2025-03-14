#include "Group.h"

Group::Group() : name(""), studentCount(0), students(nullptr) {}

Group::Group(const string& name, int studentCount) : name(name), studentCount(studentCount) {
    students = new Student[studentCount];
}

Group::~Group() {
    delete[] students;
}

string Group::getName() const {
    return name;
}

int Group::getStudentCount() const {
    return studentCount;
}

Student* Group::getStudents() const {
    return students;
}

void Group::addStudent(const Student& student, int index) {
    if (index >= 0 && index < studentCount) {
        students[index] = student;
    }
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Group: " << group.name << "\nStudents:\n";
    for (int i = 0; i < group.studentCount; ++i) {
        os << group.students[i] << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Group& group) {
    is >> group.name >> group.studentCount;
    group.students = new Student[group.studentCount];
    for (int i = 0; i < group.studentCount; ++i) {
        is >> group.students[i];
    }
    return is;
}
