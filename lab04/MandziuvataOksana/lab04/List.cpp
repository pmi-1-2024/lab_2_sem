#include "list.h"

List::List() : head(nullptr) {}

bool List::empty() const {
    return head == nullptr;
}

Link* List::front() const {
    return head;
}

void List::push_front(Link* new_elem) {
    new_elem->next = head;
    head = new_elem;
}

void List::pop_front() {
    if (head != nullptr) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

List::~List() {
    while (!empty()) pop_front();
}
