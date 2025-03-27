#include "List.h"

List::List() : head(nullptr) {}
List::~List() {
    clear();  
}

void List::removeFirst() {
    if (!head) return;  

    Link* temp = head;  
    head = head->next;  
    delete temp;        
}

void List::removeLast() {
    if (!head) return;  

    if (!head->next) {  
        delete head;
        head = nullptr;
        return;
    }

    Link* current = head;
    while (current->next->next) {  
        current = current->next;
    }

    delete current->next; 
    current->next = nullptr; 
}

void List::clear() {
    while (head) {  
        removeFirst();  
    }
}

bool List::isEmpty() const {
    return head == nullptr;  
}