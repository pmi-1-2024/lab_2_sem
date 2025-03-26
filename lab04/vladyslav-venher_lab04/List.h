#pragma once
#include <iostream>
using namespace std;

struct Node {
    Node* next;
    virtual ~Node() {}
protected:
    Node() : next(nullptr) {}
};

struct Student {
    string firstName;
    string lastName;
    double gpa;
    Student(string fn = "", string ln = "", double g = 0.0) : firstName(fn), lastName(ln), gpa(g) {}

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};

struct Student_Node : Node {
    Student info;
    Student_Node(const Student& student) : info(student) {}
};

class List {
private:
    List(const List&);
    List& operator=(const List&);
protected:
    Node* head;
    void add(Node*);
    Node* top() const { return head; }
public:
    List() : head(nullptr) {}
    ~List();
    Node* remove(Node* node = nullptr);
    bool isEmpty() const { return !head; }
};

// Реалізація методів класу List
List::~List() {
    while (!isEmpty()) {
        Node* temp = remove();
        delete temp;
    }
}

void List::add(Node* node) {
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

ostream& operator<<(ostream& os, const Student& student) {
    os << "First Name: " << student.firstName
        << ", Last Name: " << student.lastName
        << ", GPA: " << student.gpa;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    cout << "Enter first name: ";
    is >> student.firstName;
    cout << "Enter last name: ";
    is >> student.lastName;
    cout << "Enter GPA: ";
    is >> student.gpa;
    return is;
}