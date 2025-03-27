#include "Student_List.h"

Student_Link::Student_Link(const Student& s) : student(s) {}

Students_List::Students_List() : head(nullptr) {}

Students_List::~Students_List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

Link* Students_List::getHead() const { return head; }
void Students_List::setHead(Link* newHead) { head = newHead; }
