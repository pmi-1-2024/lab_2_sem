#include "Students_List.h"

void Students_List::push(const Student& s) {
    Student_Link* temp = new Student_Link(s);
    List::push(temp);
}

Student Students_List::topStudent() const {
    if (!head) return Student();
    return ((Student_Link*)head)->data;
}

Student_Link* Students_List::find(const string& recordNumber) {
    Student_Link* temp = (Student_Link*)head;
    while (temp) {
        if (temp->data.getRecordNumber() == recordNumber)
            return temp;
        temp = (Student_Link*)temp->next;
    }
    return nullptr;
}

void Students_List::insert(const Student& s, Student_Link* after) {
    if (!after) return;
    Student_Link* node = new Student_Link(s);
    node->next = after->next;
    after->next = node;
}
