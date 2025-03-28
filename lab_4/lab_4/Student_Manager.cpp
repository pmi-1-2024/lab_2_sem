#include "Student_Manager.h"

void Student_Manager::pushStudent(const Student& student) {
    studentsList.push(new Student_Link(student));
}

void Student_Manager::displayAllStudents() const {
    studentsList.display();
}

Student* Student_Manager::searchStudentByName(const std::string& name) {
    return studentsList.findByName(name);
}

void Student_Manager::popStudentByName(const std::string& name) {
    studentsList.popByName(name);
}

void Student_Manager::replaceStudentData(const std::string& name, const Student& newStudent) {
    studentsList.replaceStudent(name, newStudent);
}

bool Student_Manager::isEmpty() const {
    return studentsList.isEmpty();
}