#pragma once
#include <iostream>
using namespace std;

struct Node {
    Node* next;
    virtual ~Node() {}
protected:
    Node() : next(nullptr) {}
};


class List {
private:
    List(const List&);
    List& operator=(const List&);
protected:
    Node* head;
    void push(Node*);
    Node* top() const { return head; }
public:
    List() : head(nullptr) {}
    ~List();
    Node* remove(Node* node = nullptr);
    bool empty() const { return !head; }
};

// Реалізація методів класу List
List::~List() {
    while (!empty()) {
        Node* temp = remove();
        delete temp;
    }
}

void List::push(Node* node) {
    if (!node) return;
    node->next = head;
    head = node;
}

Node* List::remove(Node* node) {
    if (!head) return nullptr;
    if (!node) node = head;
    Node* temp = head;
    Node* prev = nullptr;
    if (temp == node) {
        head = head->next;
        node->next = nullptr;
        return node;
    }
    while (temp && temp != node) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == node) {
        prev->next = node->next;
        node->next = nullptr;
        return node;
    }
    return nullptr;
}
