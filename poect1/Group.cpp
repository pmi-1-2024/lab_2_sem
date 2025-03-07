#include "Group.h"
using namespace std;

void Group::copyFrom(const Group& other) {
    name = other.name;
    studentCount = other.studentCount;
    students = (other.studentCount > 0) ? new Student[other.studentCount] : nullptr;
    for (int i = 0; i < studentCount; ++i) {
        students[i] = other.students[i];
    }
}

void Group::clear() {
    if (students != nullptr) {
        delete[] students;
        students = nullptr;
    }
    studentCount = 0;
}

Group::Group(string name, int studentCount) : name(name), studentCount(studentCount), students(nullptr) {
    if (studentCount > 0) {
        students = new Student[studentCount];
    }
}

Group::Group(const Group& other) {
    copyFrom(other);
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        clear();
        copyFrom(other);
    }
    return *this;
}

Group::~Group() {
    clear();
}

void Group::addStudent(const Student& student) {
    Student* temp = new Student[studentCount + 1];

    for (int i = 0; i < studentCount; ++i) {
        temp[i] = students[i];
    }

    temp[studentCount] = student;

    if (students != nullptr) {
        delete[] students;
    }

    students = temp;
    ++studentCount;
}

Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        throw out_of_range("Index out of range");
    }
    return students[index];
}

Student Group::operator[](const string& surname) const {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getSurname() == surname) {  // Метод getSurname() треба додати в Student
            return students[i];
        }
    }
    throw invalid_argument("Student not found");
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

    if (group.students != nullptr) {
        delete[] group.students;
    }

    group.students = (group.studentCount > 0) ? new Student[group.studentCount] : nullptr;
    for (int i = 0; i < group.studentCount; ++i) {
        is >> group.students[i];
    }

    return is;
}


