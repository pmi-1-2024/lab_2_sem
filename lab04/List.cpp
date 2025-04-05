#include "List.h"
List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}
List::List(const List& other) : head(0) {
    if (!other.head) return; 
    head = new Link(*other.head);
    Link* current = head;
    Link* otherCurrent = other.head->next;
    while (otherCurrent) {
        current->next = new Link(*otherCurrent);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}
List& List::operator=(const List& other) {
    if (this == &other) return *this; 
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }

    head = 0;
    if (!other.head) return *this; 
    head = new Link(*other.head);
    Link* current = head;
    Link* otherCurrent = other.head->next;
    while (otherCurrent) {
        current->next = new Link(*otherCurrent);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    return *this;
}
Link* List::remove(Link* node) {
    if (!head) return 0;
    if (!node) node = head;
    Link* temp = head;

    if (temp == node) {
        head = head->next;
        node->next = 0;
        return node;
    }
    Link* prev = temp;
    temp = temp->next;
    while (temp) {
        if (temp == node) {
            prev->next = temp->next;
            node->next = 0;
            return node;
        }
        prev = temp;
        temp = temp->next;
    }

    return 0; 
}
