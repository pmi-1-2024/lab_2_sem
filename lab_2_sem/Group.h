#ifndef GROUP_H
#define GROUP_H
#include "Student.h"
#include <fstream>
using namespace std;

class Group {
private:
    string name;
    Student* students;
    int studentCount;

    void deepCopy(const Group& other) {
        name = other.name;
        studentCount = other.studentCount;
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; i++) {
            students[i] = other.students[i];
        }
    }

public:
    Group() : name(""), students(nullptr), studentCount(0) {}
    Group(string name, Student* students, int studentCount)
        : name(name), students(students), studentCount(studentCount) {}

    Group(const Group& other) {
        deepCopy(other);
    }

    Group& operator=(const Group& other) {
        if (this != &other) {
            delete[] students;
            deepCopy(other);
        }
        return *this;
    }

    ~Group() {
        delete[] students;
    }

    void addStudent(const Student& student) {
        Student* newStudents = new Student[studentCount + 1];
        for (int i = 0; i < studentCount; i++) newStudents[i] = students[i];
        newStudents[studentCount] = student;
        delete[] students;
        students = newStudents;
        studentCount++;
    }

    void addStudents(const Student* newStudents, int count) {
        if (count <= 0 || newStudents == nullptr) return;
        Student* updatedStudents = new Student[studentCount + count];
        for (int i = 0; i < studentCount; i++) updatedStudents[i] = students[i];
        for (int i = 0; i < count; i++) updatedStudents[studentCount + i] = newStudents[i];
        delete[] students;
        students = updatedStudents;
        studentCount += count;
    }

    void removeStudent(string studentName) {
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

    void display() const {
    cout << "Назва групи: " << name << endl;
    for (int i = 0; i < studentCount; i++) {
            cout << students[i] << endl;
        }
    }

    int getStudentCount() const { return studentCount; }
    Student* getStudents() const { return students; }

    void searchByGroupName(const string& groupName) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getGroup() == groupName) {
                cout << students[i] << endl;
            }
        }
    }

    void searchByAddress(const Address& address) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getAddress() == address) {
                cout << students[i] << endl;
            }
        }
    }

    void searchByRecordNumber(const string& recordNumber) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getRecordBook().getRecordNumber() == recordNumber) {
                cout << students[i] << endl;
            }
        }
    }

    void searchBySubjectName(const string& subjectName) const {
        for (int i = 0; i < studentCount; i++) {
            RecordBook recordBook = students[i].getRecordBook();
            for (int j = 0; j < recordBook.getSubjectCount(); j++) {
                if (recordBook.getSubjects()[j].getName() == subjectName) {
                    cout << students[i] << endl;
                    break;
                }
            }
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) return;
        file << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            file << students[i] << endl;
        }
        file.close();
    }

    friend istream& operator>>(istream& is, Group& group) {
        is >> group.name;
        Student student;
        while (is >> student) {
            group.addStudent(student);
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Group& group) {
        os << group.name << endl;
        for (int i = 0; i < group.studentCount; i++) {
            os << group.students[i] << endl;
        }
        return os;
    }
};

#endif