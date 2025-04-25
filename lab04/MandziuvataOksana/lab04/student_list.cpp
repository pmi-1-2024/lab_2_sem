#include "student_list.h"
#include <iostream>

StudentList::StudentList() : List() {}

void StudentList::push_front(const Student& s) {
    List::push_front(new StudentLink(nullptr, s));
}

void StudentList::remove(StudentLink* s) {
    if (head == s) {
        head = s->next;
        delete s;
        return;
    }

    Link* curr = head;
    while (curr->next != s && curr->next != nullptr) {
        curr = curr->next;
    }
    if (curr->next == s) {
        curr->next = s->next;
        delete s;
    }
}

void StudentList::print_all() const {
    StudentLink* curr = static_cast<StudentLink*>(head);
    while (curr != nullptr) {
        std::cout << curr->value;
        curr = static_cast<StudentLink*>(curr->next);
    }
}
