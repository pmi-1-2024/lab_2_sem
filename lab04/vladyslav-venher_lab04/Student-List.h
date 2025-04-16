#pragma once
#include "Student.h"

class StudentList : public List {
public:
    void push(const Student& student);
    Student_Node* top() const;
    Student_Node* find(const string& firstName, const string& lastName);
    void insert(const Student& student, Student_Node* after);
};

// Реалізація методів класу StudentList
void StudentList::push(const Student& student) {
    Student_Node* temp = new Student_Node(student);
    List::push(temp);
}

Student_Node* StudentList::top() const { return (Student_Node*)head; }

Student_Node* StudentList::find(const string& firstName, const string& lastName) {
    Student_Node* temp = (Student_Node*)head;
    while (temp) {
        if (temp->info.firstName == firstName && temp->info.lastName == lastName)
            return temp;
        temp = (Student_Node*)(temp->next);
    }
    return nullptr;
}

void StudentList::insert(const Student& student, Student_Node* after) {
    if (!after) return;
    Student_Node* newNode = new Student_Node(student);
    newNode->next = after->next;
    after->next = newNode;
}