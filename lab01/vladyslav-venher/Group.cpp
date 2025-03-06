#include "Group.h"
using namespace std;

Group::Group() : name(""), studentCount(0), students(nullptr) {}

Group::Group(const string& name, int count) : name(name), studentCount(count) {
    if (studentCount > 0) {
        students = new Student[studentCount];
    }
    else {
        students = nullptr;
    }
}

Group::Group(const Group& other) : name(other.name), studentCount(other.studentCount) {
    students = new Student[studentCount];
    for (int i = 0; i < studentCount; ++i) {
        students[i] = other.students[i];
    }
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        delete[] students;

        name = other.name;
        studentCount = other.studentCount;
        students = new Student[studentCount];

        for (int i = 0; i < studentCount; ++i) {
            students[i] = other.students[i];
        }
    }
    return *this;
}

Group::~Group() {
    delete[] students;
}

Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        throw out_of_range("Index out of range");
    }
    return students[index];
}

ostream& operator<<(ostream& os, const Group& group) {
    os << group.name << "\n" << group.studentCount << "\n";
    for (int i = 0; i < group.studentCount; ++i) {
        os << group.students[i] << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Group& group) {
    getline(is, group.name);
    is >> group.studentCount;
    is.ignore();

    delete[] group.students;  
    group.students = new Student[group.studentCount];

    for (int i = 0; i < group.studentCount; ++i) {
        is >> group.students[i];
    }
    return is;
}
