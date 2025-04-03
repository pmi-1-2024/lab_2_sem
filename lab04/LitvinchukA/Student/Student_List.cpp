#include "Student_List.h"
using namespace std;

void Student_List::push(const Student& student) {
    List::push(new Student_Link(student));
}

void Student_List::remove(const Student& student) {
    Link* link = List::find(student.getName());
    if (link) {
        List::remove(link);
    }
}

Student* Student_List::find(const string& name) const {
    Link* link = List::find(name);
    if (link) {
        Student_Link* studentLink = static_cast<Student_Link*>(link);
        if (studentLink) {
            return &studentLink->student;
        }
    }
    return nullptr;
}

void Student_List::insert(const Student& student, const string& positionName) {
    Link* position = List::find(positionName);
    List::insert(new Student_Link(student), position);
}

void Student_List::print() const {
    Link* current = head;
    while (current) {
        Student_Link* studentLink = static_cast<Student_Link*>(current);
        if (studentLink) {
            cout << studentLink->student;
        }
        current = current->next;
    }
}