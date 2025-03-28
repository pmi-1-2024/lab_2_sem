#include "Group.h"
#include <iostream>
using namespace std;

Group::Group(string n, Student* s, int count) : name(n), studentCount(count) {
    if (count > 0) {
        students = new Student[count];
        for (int i = 0; i < count; ++i) {
            students[i] = s[i];
        }
    }
    else {
        students = nullptr;
    }
}

Group::~Group() {
    delete[] students;
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

Student& Group::operator[](int index) {
    return students[index];
}

void Group::addStudent(const Student& s) {
    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; ++i) {
        newStudents[i] = students[i];
    }
    newStudents[studentCount] = s;

    delete[] students;
    students = newStudents;
    studentCount++;
}

void Group::removeStudent(const string& name) {
    if (studentCount == 0) {
        cout << "No students to remove.\n";
        return;
    }

    int indexToRemove = -1;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].GetName() == name) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        cout << "Student not found.\n";
        return;
    }

    Student* newStudents = new Student[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; ++i) {
        if (i != indexToRemove) {
            newStudents[j++] = students[i];
        }
    }

    delete[] students;
    students = newStudents;
    studentCount--;

    cout << "Student " << name << " has been removed.\n";
}

void Group::searchByName(const string& name) const {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].GetName() == name) {
            cout << students[i] << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void Group::searchByGroupName(const string& groupName) const {
    if (name == groupName) {
        printStudents();
    }
    else {
        cout << "Group name not found.\n";
    }
}

void Group::searchByRecordNumber(const string& recordNumber) const {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].GetRecordNumber() == recordNumber) {
            cout << students[i] << endl;
            return;
        }
    }
    cout << "Record number not found.\n";
}

void Group::searchByAddress(const Address& addr) const {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].GetAddress().GetCity() == addr.GetCity() &&
            students[i].GetAddress().GetStreet() == addr.GetStreet()) {
            cout << students[i] << endl;
            return;
        }
    }
    cout << "Address not found.\n";
}

void Group::printStudents() const {
    if (studentCount == 0) {
        cout << "No students in the group.\n";
        return;
    }
    for (int i = 0; i < studentCount; ++i) {
        cout << students[i] << endl;
    }
}

ostream& operator<<(ostream& out, const Group& g) {
    out << "Group: " << g.name << endl;
    for (int i = 0; i < g.studentCount; ++i) {
        out << g.students[i] << endl;
    }
    return out;
}

