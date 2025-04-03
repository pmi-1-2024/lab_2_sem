#include "Student_Manager.h"

void Student_Manager::add(const Student& student) {
    studentList.push(student);
    cout << "�������� ������." << endl << endl;
}

void Student_Manager::remove(const Student& student) {
    studentList.remove(student);
    cout << "�������� ��������." << endl << endl;
}

Student* Student_Manager::findName(const string& name) {
    Student* foundStudent = studentList.find(name);
    if (foundStudent) {
        cout << "��������: " << *foundStudent << endl;
    }
    else {
        cout << "�������� �� ��������." << endl << endl;
    }
    return foundStudent;
}

void Student_Manager::replace(const string& name, const Student& newStudentData) {
    Student* student = findName(name);
    if (student) {
        *student = newStudentData;
    }
    cout << "�������� �������." << endl << endl;
}

void Student_Manager::print() const {
    cout << "������ ��������: " << endl << endl;
    studentList.print();
}