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

Student_Link* Students_List::findByName(string fName) {
    Link* current = head;
    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current); 
        if (sLink->student.firstName == fName) return sLink;
        current = current->next;
    }
    return nullptr;
}

Student_Link* Students_List::findByLastName(string lName) {
    Link* current = head;
    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current); 
        if (sLink->student.lastName == lName) return sLink;
        current = current->next;
    }
    return nullptr;
}

void Students_List::findByGroup(string grp) {
    Link* current = head;
    bool found = false;
    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current); 
        if (sLink->student.group == grp) {
            sLink->student.display();
            found = true;
        }
        current = current->next;
    }
    if (!found) cout << "No students found in group " << grp << endl;
}

void Students_List::remove(string fName, string lName) {
    Link* current = head; 
    Link* prev = nullptr;

    while (current) {
        Student_Link* sLink = static_cast<Student_Link*>(current);
        if (sLink->student.firstName == fName && sLink->student.lastName == lName) {
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