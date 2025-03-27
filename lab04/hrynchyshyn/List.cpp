#include "List.h"

List::List() : head(nullptr) {}

List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}
