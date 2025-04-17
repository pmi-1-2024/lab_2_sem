#pragma once
#include <iostream>
using namespace std;


struct Node {
    Phone data;
    Node* next;
    Node(T d) : data(d), next(nullptr) {}
};


class Phone_List {
private:
    Node* head;
public:
    List() : head(nullptr) {}
    ~List() { clear(); }

    void push(Phone data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    bool find(Phone data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(Phone data) {
        if (!head) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != data) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void show() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

