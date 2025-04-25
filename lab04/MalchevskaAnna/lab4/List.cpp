#include "List.h"

List::List() : head(nullptr) {}
List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}
void List::push(Link* node) {
    node->next = head;
    head = node;
}
Link* List::top() const {
    return head;
}
Link* List::remove(Link* node) {
    if (!node) node = head;
    if (node) {
        head = node->next;
        delete node;
    }
    return head;
}
bool List::empty() const {
    return !head;
}