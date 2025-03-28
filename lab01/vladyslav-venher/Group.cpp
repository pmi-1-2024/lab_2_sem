#include "Group.h"
using namespace std;

Group::Group() : name(""), students(nullptr), studentCount(0) {}

Group::Group(string name, Student* students, int studentCount)
    : name(name), students(students), studentCount(studentCount) {
}


Group::Group(const Group& other) {
    deepCopy(other);
}


Group& Group::operator=(const Group& other) {
    if (this != &other) {
        delete[] students;
        deepCopy(other);
    }
    return *this;
}


Group::~Group() {
    if (students) {
        delete[] students;
    }
}



int Group::getStudentCount() const {
    return studentCount;
}

Student* Group::getStudents() const { 
    return students; 
}


void Group::addStudent(const Student& student) {
    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; i++) newStudents[i] = students[i];
    newStudents[studentCount] = student;
    delete[] students;
    students = newStudents;
    studentCount++;
}


void Group::addStudents(const Student* newStudents, int count) {
    if (count <= 0 || newStudents == nullptr) return;
    Student* updatedStudents = new Student[studentCount + count];
    for (int i = 0; i < studentCount; i++) updatedStudents[i] = students[i];
    for (int i = 0; i < count; i++) updatedStudents[studentCount + i] = newStudents[i];
    delete[] students;
    students = updatedStudents;
    studentCount += count;
}


void Group::removeStudent(string studentName) {
    if (studentCount == 0) return;
    Student* newStudents = new Student[studentCount - 1];
    int j = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() != studentName) {
            newStudents[j] = students[i];
            j++;
        }
    }
    delete[] students;
    students = newStudents;
    studentCount--;
}


void Group::searchByGroup(const string& groupName) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getGroup() == groupName) {
            cout << students[i] << endl;
        }
    }
}


void Group::searchByAddress(const Address& address) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getAddress() == address) {
            cout << students[i] << endl;
        }
    }
}


void Group::searchByZalikovkaNumber(const string& zalikovkaNumber) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getZalikovka().getZalikovkaNumber() == zalikovkaNumber) {
            cout << students[i] << endl;
        }
    }
}


void Group::searchBySubject(const string& subjectName) const {
    for (int i = 0; i < studentCount; i++) {
        Zalikovka zalikovka= students[i].getZalikovka();
        for (int j = 0; j < zalikovka.getSubjectCount(); j++) {
            if (zalikovka.getSubjects()[j].getName() == subjectName) {
                cout << students[i] << endl;
                break;
            }
        }
    }
}


Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        throw out_of_range("Index out of range");
    }
    return students[index];
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Group: " << group.name << "\n";
    for (int i = 0; i < group.studentCount; i++) {
        os << group.students[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Group& group) {
    is >> group.name;
    Student student;    
    while (is >> student) {
        group.addStudent(student);
    }
    return is;
}