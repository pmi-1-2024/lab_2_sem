#include "Student_list.h"

void Student_List::push(const Student& student) {
    Student_Link* temp = new Student_Link(student);
    List::push(temp);
}

Student_Link* Student_List::top() const { return (Student_Link*)head; }

Student_Link* Student_List::find(const Student& student) {
    Student_Link* temp = (Student_Link*)head;
    while (temp) {
        if (temp->data.name == student.name && temp->data.surname == student.surname) 
            return temp;
        temp = (Student_Link*)(temp->next);
    }
    return nullptr;
}

void Student_List::insert(const Student& student, Student_Link* after) {
    if (!after) return;

    Student_Link* newNode = new Student_Link(student);
    newNode->next = after->next;
    after->next = newNode;
}
