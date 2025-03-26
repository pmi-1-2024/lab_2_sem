#pragma once
#include "List.h"

class StudentList : public List {
public:
    void addStudent(const Student& student);
    Student_Node* getTop() const;
    Student_Node* searchByName(const string& firstName, const string& lastName);
    void insertAfter(const Student& student, Student_Node* after);
};

// Реалізація методів класу StudentList
void StudentList::addStudent(const Student& student) {
    Student_Node* temp = new Student_Node(student);
    List::add(temp);
}

Student_Node* StudentList::getTop() const { return (Student_Node*)head; }

Student_Node* StudentList::searchByName(const string& firstName, const string& lastName) {
    Student_Node* temp = (Student_Node*)head;
    while (temp) {
        if (temp->info.firstName == firstName && temp->info.lastName == lastName)
            return temp;
        temp = (Student_Node*)(temp->next);
    }
    return nullptr;
}

void StudentList::insertAfter(const Student& student, Student_Node* after) {
    if (!after) return;
    Student_Node* newNode = new Student_Node(student);
    newNode->next = after->next;
    after->next = newNode;
}