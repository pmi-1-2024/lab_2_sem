#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T d) : data(d), next(nullptr) {}
};

template<typename T>
class List {
private:
    Node<T>* head;
public:
    List() : head(nullptr) {}
    ~List() { clear(); }

    void push(T data) {
        Node<T>* temp = new Node<T>(data);
        temp->next = head;
        head = temp;
    }

    bool find(T data) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == data) return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(T data) {
        if (!head) return;
        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T>* current = head;
        while (current->next && current->next->data != data) {
            current = current->next;
        }
        if (current->next) {
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void show() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
