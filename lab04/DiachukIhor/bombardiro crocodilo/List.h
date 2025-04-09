#ifndef LIST_H
#define LIST_H
#include "Link.h"
using namespace std;

class List {
    List(const List&);
    List& operator =(const List&);

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
    List() : head(nullptr) {}
    virtual ~List();

    Link* remove(Link* node = nullptr);
    bool empty() const { return !head; }
};

#endif 
