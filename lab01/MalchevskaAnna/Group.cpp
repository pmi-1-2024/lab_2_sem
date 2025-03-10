#include "Group.h"
#include <fstream> 

Group::Group() : name(""), students(nullptr), studentCount(0) {}

Group::Group(string name, Student* students, int studentCount)
    : name(name), students(students), studentCount(studentCount) {}

Group::Group(const Group& other) {
    name = other.name;
    studentCount = other.studentCount;
    students = new Student[studentCount];  
    for (int i = 0; i < studentCount; i++) {
        students[i] = other.students[i];  
    }
}

Group& Group::operator=(const Group& other) {
    if (this == &other) return *this; 

    delete[] students; 

    name = other.name;
    studentCount = other.studentCount;
    students = new Student[studentCount];  
    for (int i = 0; i < studentCount; i++) {
        students[i] = other.students[i];  
    }

    return *this;
}



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
    cout << *this;
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
        outFile << *this;  
        outFile.close();
    }
    else {
        cout << "Error opening file for saving." << endl;
    }
}

ostream& operator<<(ostream& os, const Group& group) {
    os << group.name << endl; 
    os << group.studentCount << endl; 
    for (int i = 0; i < group.studentCount; i++) {
        os << group.students[i] << endl; 
    }
    return os;
}

istream& operator>>(istream& is, Group& group) {
    is >> group.name;  
    is >> group.studentCount; 

    delete[] group.students;  
    group.students = new Student[group.studentCount];  

    for (int i = 0; i < group.studentCount; i++) {
        is >> group.students[i]; 
    }
    return is;
}

void Group::loadFromFile(const string& students) {
    ifstream inFile(students);
    if (inFile.is_open()) {
        inFile >> *this;  
        inFile.close();
    }
    else {
        cout << "Error opening file for loading." << endl;
    }
}

Student& Group::operator[](int index) {  
    if (index < 0 || index >= studentCount) {
        throw out_of_range("Index out of range");
    }
    return students[index];
}

