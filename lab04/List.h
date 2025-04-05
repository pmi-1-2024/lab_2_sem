#ifndef LIST_H
#define LIST_H
#include "Link.h"
using namespace std;
class List {
protected:
    Link* head;
    void push(Link* node) {
        if (!head) head = node;
        else {
            node->next = head;
            head = node;
        }
    }
    Link* top() const { return head; }

public:
    List() : head(0) {}
    ~List();
    List(const List& other);
    List& operator=(const List& other);

    Link* remove(Link* node = 0);
    bool empty() const { return !head; }
};

#endif
