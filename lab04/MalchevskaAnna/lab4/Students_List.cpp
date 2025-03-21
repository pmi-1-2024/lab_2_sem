#include "Students_List.h"

Students_List::Students_List() : List() {}
Students_List::Students_List(const Students_List& other) {
    Link* current = other.head;
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        this->addStudent(studentLink->data); 
        current = current->next;
    }
}
Students_List& Students_List::operator=(const Students_List& other) {
    if (this == &other) {
        return *this;  
    }
    while (head) {
        remove();
    }
    Link* current = other.head;
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        this->addStudent(studentLink->data);
        current = current->next;
    }

    return *this;
}
Students_List::~Students_List() {
}

void Students_List::addStudent(const Student& s) {
    push(new Student_Link(s));
}
void Students_List::printAll() const {
    if (empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    Link* current = top();
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        studentLink->data.print();
        current = current->next;
    }
}
Student_Link* Students_List::findStudentByName(const string& name) const {
    if (empty()) {
        cout << "No students in the list." << endl;
        return nullptr;
    }
    Link* current = top();
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink->data.name == name) {
            return studentLink;
        }
        current = current->next;
    }
    return nullptr;
}
Student_Link* Students_List::findStudentByGroup(const string& group) const {
    if (empty()) {
        cout << "No students in the list." << endl;
        return nullptr;
    }
    Link* current = top();
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink->data.group == group) {
            return studentLink;
        }
        current = current->next;
    }
    return nullptr;
}
Student_Link* Students_List::findStudentByAddress(const string& address) const {
    if (empty()) {
        cout << "No students in the list." << endl;
        return nullptr;
    }
    Link* current = top();
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink->data.address == address) {
            return studentLink;
        }
        current = current->next;
    }
    return nullptr;
}
bool Students_List::removeStudentByName(const string& name) {
    if (empty()) {
        cout << "No students in the list. Nothing to remove." << endl;
        return false;
    }
    Link* current = top();
    Link* prev = nullptr;
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink->data.name == name) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            delete studentLink;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

int Students_List::getSize() const {
    int count = 0;
    Link* current = top();
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

Student Students_List::getStudentAt(int index) const {
    if (index < 0 || index >= getSize()) {
        throw out_of_range("Index out of range");
    }
    Link* current = top();
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Student_Link* studentLink = static_cast<Student_Link*>(current);
    return studentLink->data;
}