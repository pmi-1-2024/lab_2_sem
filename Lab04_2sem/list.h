#pragma once

#include "link.h"
#include <iostream>

using namespace std;

template <typename T>
class List {
private:
    Link<T>* head;

public:
    List();
    ~List();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void clear();
    bool empty() const;

    void print(ostream& os) const;

protected:
    Link<T>* getHead() const;
};

template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_front(const T& value) {
    Link<T>* newNode = new Link<T>(value);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::push_back(const T& value) {
    Link<T>* newNode = new Link<T>(value);
    if (!head) {
        head = newNode;
    }
    else {
        Link<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (head) {
        Link<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void List<T>::clear() {
    while (head) {
        pop_front();
    }
}

template <typename T>
bool List<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::print(ostream& os) const {
    Link<T>* current = head;
    while (current) {
        os << current->data << endl;
        current = current->next;
    }
}

template <typename T>
Link<T>* List<T>::getHead() const {
    return head;
}
