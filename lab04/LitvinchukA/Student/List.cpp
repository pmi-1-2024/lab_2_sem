#include "List.h"
#include "Student_Link.h"
using namespace std;

List::List() : head(nullptr) {}

List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::push(Link* link) {
    link->next = head;
    head = link;
}

Link* List::top() const {
    return head;
}

void List::remove(Link* link) {
    if (head == link) {
        head = head->next;
    }
    else {
        Link* current = head;
        while (current && current->next != link) {
            current = current->next;
        }
        if (current) {
            current->next = link->next;
        }
    }
    delete link;
}

bool List::empty() const {
    return head == nullptr;
}

Link* List::find(const string& name) const {
    Link* current = head;
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink && studentLink->student.getName() == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::insert(Link* link, Link* position) {
    if (position == nullptr) {
        push(link);
    }
    else {
        link->next = position->next;
        position->next = link;
    }
}