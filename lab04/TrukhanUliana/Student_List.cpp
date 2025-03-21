#include "Student_list.h"

void Student_List::add(string n, string sn, double a) {
    Student_Link* temp = new Student_Link(n, sn, a);
    List::add(temp);
}

Student_Link* Student_List::top() const { return (Student_Link*)head; }

Student_Link* Student_List::find(string n, string sn) {
    Student_Link* temp = (Student_Link*)head;
    while (temp) {
        if (temp->name == n && temp->surname == sn) 
            return temp;
        temp = (Student_Link*)(temp->next);
    }
    return nullptr;
}

void Student_List::insert(string n, string sn, double a, Student_Link* after) {
    if (!after) return;

    Student_Link* newNode = new Student_Link(n, sn, a);
    newNode->next = after->next;
    after->next = newNode;
}
