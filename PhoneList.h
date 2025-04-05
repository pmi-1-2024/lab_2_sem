#ifndef PHONELIST_H
#define PHONELIST_H

#include "Phone.h"

struct Link {
    Link* next;
    virtual ~Link() {}
protected:
    Link() : next(0) {}
};

struct Phone_Link : public Link {
    Phone* data;
    Phone_Link(Phone* p) : data(p) {}
};

class List {
protected:
    Link* head;
    void push(Link* node) {
        if (!head) head = node;
        else { node->next = head; head = node; }
    }
    Link* top() const { return head; }
public:
    List() : head(0) {}
    virtual ~List();

    Link* remove(Link* node = 0);
    bool empty() const { return !head; }
};

List::~List() {
    while (head) {
        Link* temp = head;
        head = head->next;
        delete temp;
    }
}

Link* List::remove(Link* node) {
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

class Phone_List : public List {
public:
    void push(Phone* p) {
        Phone_Link* link = new Phone_Link(p);
        List::push(link);
    }

    Phone_Link* findByName(string target) {
        Phone_Link* temp = (Phone_Link*)head;
        while (temp) {
            if (temp->data->getName() == target)
                return temp;
            temp = (Phone_Link*)temp->next;
        }
        return 0;
    }

    void printAll(ostream& out) const {
        Phone_Link* temp = (Phone_Link*)head;
        while (temp) {
            out << *(temp->data);
            temp = (Phone_Link*)temp->next;
        }
    }
};

#endif
