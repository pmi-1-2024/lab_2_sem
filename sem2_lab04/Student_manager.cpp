#include "student_manager.h"
#include <fstream>

void Student_Manager::addStudent(const Student& student) {
    students.addStudent(student);
}

void Student_Manager::removeStudent(const string& firstName, const string& lastName) {
    students.removeStudent(firstName, lastName);
}

void Student_Manager::replaceStudent(const string& firstName, const string& lastName, const Student& newStudent) {
    students.replaceStudent(firstName, lastName, newStudent);
}

void Student_Manager::findStudent(const string& firstName, const string& lastName) {
    Student* student = students.findStudent(firstName, lastName);
    if (student) {
        cout << *student << endl;
    }
    else {
        cout << "Student not found!" << endl;
    }
}

void Student_Manager::printAllStudents() const {
    students.printAllStudents(cout);
}

void Student_Manager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Student student;
        while (file >> student) {
            students.addStudent(student);
        }
        file.close();
    }
    else {
        cout << "Failed to open file!" << endl;
    }
}

void Student_Manager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        students.printAllStudents(file);
        file.close();
    }
    else {
        cout << "Failed to open file!" << endl;
    }
}
