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
        cout << "Студента видалено.\n";
    } else {
        cout << "Студента не знайлено.\n";
    }
}

void Student_Manager::findStudent(const Student& student) const {
    Student_Link* node = list.find(student);
    if (node) {
        cout << "Студент: " << node->data << endl;
    } else {
        cout << "Студента не знайлено.\n";
    }
}

void Student_Manager::updateStudent(const Student& oldStudent, const Student& updatedStudent) {
    Student_Link* node = list.find(oldStudent);
    if (node) {
        node->data = updatedStudent;
        cout << "Студента оновлено\n";
    } else {
        cout << "Студента не знайлено.\n";
    }
}

void Student_Manager::displayAll() const {
    cout << "\nУсі студенти:\n";
    list.printAll();
}
