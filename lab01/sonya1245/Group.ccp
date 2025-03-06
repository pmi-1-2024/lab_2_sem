#include "Group.h"
#include "Student.h" 
#include "Address.h" 
#include "RecordBook.h" 

Group::Group() : name(""), students(nullptr), studentCount(0) {}

Group::Group(const string& name) : name(name), students(nullptr), studentCount(0) {}

Group::Group(const Group& other) {
    name = other.name;
    studentCount = other.studentCount;
    students = new Student[studentCount];
    for (int i = 0; i < studentCount; i++) {
        students[i] = other.students[i];
    }
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        if (students != nullptr) {
            delete[] students;
        }

        name = other.name;
        studentCount = other.studentCount;
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; i++) {
            students[i] = other.students[i];
        }
    }
    return *this;
}


Group::~Group() {
    if (students != nullptr) {
        delete[] students;
    }

void Group::addStudent(const Student& student) {
    Student* temp = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; i++) {
        temp[i] = students[i];
    }
    temp[studentCount] = student;
    delete[] students;
    students = temp;
    studentCount++;
}

void Group::searchByName(const string& name) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() == name) {
            cout << students[i] << "\n";
        }
    }
}

void Group::searchByGroupName(const string& groupName) const {
    if (name == groupName) {
        for (int i = 0; i < studentCount; i++) {
            cout << students[i] << "\n";
        }
    }
}

void Group::searchByRecordNumber(const string& recordNumber) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRecordNumber() == recordNumber) {
            cout << students[i] << "\n";
        }
    }
}

void Group::searchByAddress(const Address& address) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getAddress() == address) {
            cout << students[i] << "\n";
        }
    }
}

void Group::searchByCity(const string& city) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getAddress().getCity() == city) {
            cout << students[i] << "\n";
        }
    }
}

void Group::searchBySubjectName(const string& subjectName) const {
    for (int i = 0; i < studentCount; i++) {
        const RecordBook& recordBook = students[i].getRecordBook();
        for (int j = 0; j < recordBook.getSubjectCount(); j++) {
            if (recordBook.getSubjects()[j].getName() == subjectName) {
                cout << students[i] << "\n";
            }
        }
    }
}

void Group::searchBySemester(int semester) const {
    for (int i = 0; i < studentCount; i++) {
        const RecordBook& recordBook = students[i].getRecordBook();
        for (int j = 0; j < recordBook.getSubjectCount(); j++) {
            if (recordBook.getSubjects()[j].getSemester() == semester) {
                cout << students[i] << "\n";
            }
        }
    }
}

void Group::printStudents() const {
    for (int i = 0; i < studentCount; i++) {
        cout << students[i] << "\n";
    }
}

Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        return students[0]; 
    }
    return students[index];

istream& operator>>(istream& in, Group& group) {
    cout << "Enter group name: ";
    in >> group.name;
    cout << "Enter number of students: ";
    in >> group.studentCount;
    group.students = new Student[group.studentCount];
    for (int i = 0; i < group.studentCount; i++) {
        in >> group.students[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Group& group) {
    cout << "\033[32m";
    out << "Group Name: " << group.name << "\n";
    for (int i = 0; i < group.studentCount; i++) {
        out << group.students[i] << "\n";
        cout << "\033[0m";
    }
    return out;
}