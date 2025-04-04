#include "Student_Manager.h"

void Student_Manager::pushStudent(const Student& student) {
    studentsList.push(new Student_Link(student)); 
}


void Student_Manager::displayAllStudents() const {
    studentsList.display();  
}


void Student_Manager::popStudentByName(const string& name) {
    studentsList.pop(name);  
}


bool Student_Manager::isEmpty() const {
    cout << "empty";
    return studentsList.isEmpty();  
}



