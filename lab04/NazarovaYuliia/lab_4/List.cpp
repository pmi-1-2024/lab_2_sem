#include "List.h"

List::List() : head(nullptr) {}
List::~List() {
    {
        Link* current = head;
        while (current) {
            Link* temp = current;
            current = current->next;
            delete temp;
        }
    }
}