#include "students_list.h"

void Students_List::addStudent(const Student& student) {
    push_back(student);
}

void Students_List::removeStudent(const string& firstName, const string& lastName) {
    Link<Student>* current = getHead();
    Link<Student>* previous = nullptr;

    while (current) {
        if (current->data.getFirstName() == firstName && current->data.getLastName() == lastName) {
            if (previous) {
                previous->next = current->next;
            }
            else {
                pop_front();
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

Student* Students_List::findStudent(const string& firstName, const string& lastName) {
    Link<Student>* current = getHead();
    while (current) {
        if (current->data.getFirstName() == firstName && current->data.getLastName() == lastName) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void Students_List::replaceStudent(const string& firstName, const string& lastName, const Student& newStudent) {
    Student* student = findStudent(firstName, lastName);
    if (student) {
        *student = newStudent;
    }
}

void Students_List::printAllStudents(ostream& os) const {
    print(os);
}
