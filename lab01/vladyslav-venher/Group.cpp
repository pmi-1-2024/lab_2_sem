#include "Group.h"
using namespace std;

Group::Group() : name(""), studentCount(0), students(nullptr) {}

Group::Group(string name, int studentCount, Student* student) : name(name), studentCount(studentCount) {
    if (studentCount > 0) {
        students = new Student[studentCount];

        for (int i = 0; i < studentCount; i++) {
            students[i] = student[i];
        }
    }
    else {
        students = nullptr;
    }
}

Group::Group(const Group& group) : name(group.name), studentCount(group.studentCount) {
    if (studentCount > 0) {
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; ++i) {
            students[i] = group.students[i];
        }
    }
    else {
        students = nullptr;
    }
}


Group& Group::operator=(const Group& group) {
    if (this == &group) return *this;

    delete[] students;

    name = group.name;
    studentCount = group.studentCount;
    students = (studentCount > 0) ? new Student[studentCount] : nullptr;

    for (int i = 0; i < studentCount; i++) {
        students[i] = group.students[i];
    }
    return *this;
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


void Group::addStudent(const Student& student) {
    Student temporaryStudent = student;
    addStudents(&student, 1);
    saveToFile("students.txt");
}

void Group::addStudents(const Student* newStudents, int newCount) {
    if (newCount <= 0) return;
    Student* updatedStudents = new Student[studentCount + newCount];

    if (students != nullptr) {
        for (int i = 0; i < studentCount; i++) {
            updatedStudents[i] = students[i];
        }
        delete[] students;
    }
    for (int i = 0; i < newCount; i++) {
        updatedStudents[studentCount + i] = newStudents[i];
    }
    students = updatedStudents;
    studentCount += newCount;
}


void Group::removeStudent(string studentName) {
    if (studentCount == 0) {
        cout << "No students in the group to remove.\n";
        return;
    }

    int newSize = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() != studentName) {
            newSize++;
        }
    }

    if (newSize == studentCount) {
        cout << "Student not found.\n";
        return;
    }

    Student* newStudents = new Student[newSize];
    int j = 0;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getName() != studentName) {
            newStudents[j++] = students[i];
        }
    }

    delete[] students;
    students = newStudents;
    studentCount = newSize;

    saveToFile("students.txt");
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
void Group::searchByZalikovkaNumber(const string& zalikovka) const {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getZalikovka().getZalikovkaNumber() == zalikovka) {
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

void Group::saveToFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Could not open file for reading.\n";
        return;
    }

    Student* allStudents = nullptr;
    int total = 0;
    readFromFile(inFile, total, allStudents);
    inFile.close();

    int newTotal = 0;
    for (int i = 0; i < total; i++) {
        if (allStudents[i].getGroup() != this->name) {
            newTotal++;
        }
    }
    newTotal += studentCount;

    Student* updatedStudents = new Student[newTotal];
    int index = 0;

    for (int i = 0; i < total; i++) {
        if (allStudents[i].getGroup() != this->name) {
            updatedStudents[index++] = allStudents[i];
        }
    }
    for (int i = 0; i < studentCount; i++) {
        updatedStudents[index++] = students[i];
    }

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Could not open file for writing.\n";
        delete[] allStudents;
        delete[] updatedStudents;
        return;
    }

    outFile << newTotal << endl;
    for (int i = 0; i < newTotal; i++) {
        outFile << updatedStudents[i];
    }
    outFile.close();

    delete[] allStudents;
    delete[] updatedStudents;
}


Student& Group::operator[](int index) {
    if (index < 0 || index >= studentCount) {
        throw out_of_range("Index out of range");
    }
    return students[index];
}

ostream& operator<<(ostream& os, const Group& group) {
    os << "Група: " << group.name << "\n";
    for (int i = 0; i < group.studentCount; i++) {
        os << group.students[i] << endl;
    }
    os << "END" << endl;
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