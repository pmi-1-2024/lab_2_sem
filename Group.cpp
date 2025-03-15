#include "Group.h"

Group::Group() : name(""), studentCount(0), students(nullptr) {}

Group::Group(const string& name, int studentCount) : name(name), studentCount(studentCount) {
    students = new Student[studentCount];
}

Group::Group(const Group& other) : name(other.name), studentCount(other.studentCount) {
    if (studentCount > 0) {
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; ++i) {
            students[i] = other.students[i];
        }
    }
    else {
        students = nullptr;
    }
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        delete[] students;

        name = other.name;
        studentCount = other.studentCount;

        if (studentCount > 0) {
            students = new Student[studentCount];
            for (int i = 0; i < studentCount; ++i) {
                students[i] = other.students[i];
            }
        }
        else {
            students = nullptr;
        }
    }
    return *this;
}

Group::~Group() {
    if (students) {
        delete[] students;
        students = nullptr;
    }
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
