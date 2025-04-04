#include "List.h"
#include <iostream>



List::~List() {
    Link* current = head;
    while (current != nullptr) {
        Link* temp = current;
        current = current->next;
        delete temp;
    }
}

void List::push(Student_Link* newLink) {
    if (head == nullptr) {
        head = newLink;
    }
    else {
        Link* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newLink;
    }
}

void List::display() const {
    Link* current = head;
    while (current != nullptr) {
        static_cast<Student_Link*>(current)->student.display();
        current = current->next;
    }
}

Student* List::findByName(const string& name) {
    Link* current = head;
    while (current != nullptr) {
        if (static_cast<Student_Link*>(current)->student.name == name) {
            return &static_cast<Student_Link*>(current)->student;
        }
        current = current->next;
    }
    return nullptr;
}

void List::popByName(const string& name) {
    Link* current = head;
    Link* prev = nullptr;
    while (current != nullptr && static_cast<Student_Link*>(current)->student.name != name) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return;  

    if (prev == nullptr) {
        head = current->next;  
    }
    else {
        prev->next = current->next;
    }
    delete current;
}

void List::replaceStudent(const string& name, const Student& newStudent) {
    Link* current = head;
    while (current != nullptr) {
        if (static_cast<Student_Link*>(current)->student.name == name) {
            static_cast<Student_Link*>(current)->student = newStudent;
            return;
        }
        current = current->next;
    }

}

bool List::isEmpty() const {
    return head == nullptr;
}