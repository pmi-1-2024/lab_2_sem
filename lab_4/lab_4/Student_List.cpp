#include "Student_List.h"
#include <iostream>

Students_List::Students_List() {}

Students_List::~Students_List() {}

void Students_List::pushStudent(const Student& student) {
    Student_Link* newStudentLink = new Student_Link(student);
    studentList.push(newStudentLink);
}

void Students_List::displayAllStudents() const {
    studentList.display();
}

Student* Students_List::searchStudentByName(const std::string& name) {
    return studentList.findByName(name);
}

void Students_List::popStudentByName(const std::string& name) {
    studentList.popByName(name);
}

void Students_List::replaceStudentData(const std::string& name, const Student& newStudent) {
    studentList.replaceStudent(name, newStudent);
}