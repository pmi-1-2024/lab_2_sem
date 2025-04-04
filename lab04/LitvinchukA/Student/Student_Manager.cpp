#include "Student_Manager.h"

void Student_Manager::add(const Student& student) {
    studentList.push(student);
    cout << "Студента додано." << endl << endl;
}

void Student_Manager::remove(const Student& student) {
    studentList.remove(student);
    cout << "Студента вилучено." << endl << endl;
}

Student* Student_Manager::findName(const string& name) {
    Student* foundStudent = studentList.find(name);
    if (foundStudent) {
        cout << "Знайдено: " << *foundStudent << endl;
    }
    else {
        cout << "Студента не знайдено." << endl << endl;
    }
    return foundStudent;
}

void Student_Manager::replace(const string& name, const Student& newStudentData) {
    Student* student = findName(name);
    if (student) {
        *student = newStudentData;
    }
    cout << "Студента замінено." << endl << endl;
}

void Student_Manager::print() const {
    cout << "Список студентів: " << endl << endl;
    studentList.print();
}