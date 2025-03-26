#include "Student_Manager.h"
#include <iostream>
using namespace std;

void Student_Manager::addStudent(const Student& student) {
    list.push(student);
}

void Student_Manager::removeStudent(const Student& student) {
    Student_Link* node = list.find(student);
    if (node) {
        list.remove(node);
        delete node;
        cout << "�������� ��������.\n";
    } else {
        cout << "�������� �� ��������.\n";
    }
}

void Student_Manager::findStudent(const Student& student) const {
    Student_Link* node = list.find(student);
    if (node) {
        cout << "�������: " << node->data << endl;
    } else {
        cout << "�������� �� ��������.\n";
    }
}

void Student_Manager::updateStudent(const Student& oldStudent, const Student& updatedStudent) {
    Student_Link* node = list.find(oldStudent);
    if (node) {
        node->data = updatedStudent;
        cout << "�������� ��������\n";
    } else {
        cout << "�������� �� ��������.\n";
    }
}

void Student_Manager::displayAll() const {
    cout << "\n�� ��������:\n";
    list.printAll();
}
