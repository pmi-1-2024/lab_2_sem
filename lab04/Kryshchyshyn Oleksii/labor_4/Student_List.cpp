#include "Student_List.h"
#include <iostream>
using namespace std;
void Students_List::push(const Student& student) {
    Student_Link* newStudentLink = new Student_Link(student);
    List::push(newStudentLink);
}
void Students_List::display() const {
    List::display();
}

void Students_List::pop(const string& name) {
    List::pop(name); 
}
