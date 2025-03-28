#include "StudentsList.h"

void Students_List::add(Link* newLink) {
    newLink->next = head;
    head = newLink;
}

void Students_List::display() {
    Link* current = head;
    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current); 
        sLink->student.display();
        current = current->next;
    }
}

void Students_List::remove(string fName, string lName) {
    Link* current = head; 
    Link* prev = nullptr;

    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current);
        if (sLink->student.getFirstName() == fName && sLink->student.getLastName() == lName) {
            if (prev) prev->next = current->next;
            else head = current->next;

            delete current;
            cout << "Student " << fName << " " << lName << " removed successfully.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Student not found.\n";
}

void Students_List::push(Student s) {
    Student_Link* newLink = new Student_Link(s);
    newLink->next = head;
    head = newLink;
}

Student Students_List::top() const {
    if (head)
        return static_cast<Student_Link*>(head)->student;
    throw runtime_error("The list is empty!");
}

Student_Link* Students_List::find(Student s) {
    Link* current = head;
    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current);
        if (sLink->student.getFirstName() == s.getFirstName() && sLink->student.getLastName() == s.getLastName())
            return sLink;
        current = current->next;
    }
    return nullptr;
}

void Students_List::insert(Student s, Student_Link* after) {
    if (!after) return;
    Student_Link* newLink = new Student_Link(s);
    newLink->next = after->next;
    after->next = newLink;
}