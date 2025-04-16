#include "List.h"

List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

Link* List::remove(Link* node) {
    if (!head) return nullptr;

    if (!node) node = head;
    Link* temp = head;

    if (temp == node) {
        head = head->next;
        node->next = nullptr;
        return node;
    }

    Link* prev = temp;
    temp = temp->next;
    while (temp) {
        if (temp == node) {
            prev->next = temp->next;
            node->next = nullptr;
            return node;
        }
        prev = temp;
        temp = temp->next;
    }
    return nullptr;
}
