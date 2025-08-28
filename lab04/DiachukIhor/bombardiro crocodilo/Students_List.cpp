#include "Students_List.h"
#include <iostream>
using namespace std;

void Students_List::push(const Student& student) {
    Student_Link* temp = new Student_Link(student);
    List::push(temp);
}

Student_Link* Students_List::find(const Student& student) const {
    Student_Link* temp = (Student_Link*)head;
    while (temp) {
        if (temp->data.id == student.id) {
            return temp;
        }
        temp = (Student_Link*)temp->next;
    }
    return nullptr;
}

void Students_List::insert(const Student& student, Student_Link* after) {
    if (!after) return;
    Student_Link* temp = new Student_Link(student);
    temp->next = after->next;
    after->next = temp;
}

void Students_List::printAll() const {
    Student_Link* temp = (Student_Link*)head;
    while (temp) {
        cout << temp->data << endl;
        temp = (Student_Link*)temp->next;
    }
}
