#pragma once
#include "Student-List.h"


class StudentManager {
private:
    StudentList list;
public:
    void addNewStudent(const Student& student);
    void deleteStudent(const string& firstName, const string& lastName);
    Student_Node* findStudent(const string& firstName, const string& lastName);
    void updateStudent(const string& firstName, const string& lastName);
    void displayStudents();
};


// Реалізація методів класу StudentManager
void StudentManager::addNewStudent(const Student& student) {
    list.push(student);
}

void StudentManager::deleteStudent(const string& firstName, const string& lastName) {
    Student_Node* stud = list.find(firstName, lastName);
    if (stud) {
        delete list.remove(stud);
    }
    else {
        cout << "Student not found!\n";
    }
}

Student_Node* StudentManager::findStudent(const string& firstName, const string& lastName) {
    return list.find(firstName, lastName);
}

void StudentManager::updateStudent(const string& firstName, const string& lastName) {
    Student_Node* student = list.find(firstName, lastName);
    if (student) {
        cout << "Enter new student data: \n";
        cin >> student->info;
        cout << "Student information updated successfully!\n";
    }
    else {
        cout << "Student not found!\n";
    }
}

void StudentManager::displayStudents() {
    Student_Node* temp = list.top();
    while (temp) {
        cout << temp->info << endl;
        temp = (Student_Node*)temp->next;
    }
}