#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Name.h"
#include "Group.h"
#include "Address.h"
#include "RecordBook.h"
using namespace std;

class Student {
public:
    Name name;
    Group group;
    Address address;
    RecordBook recordBook;

    Student(Name n, Group g, Address a, RecordBook rb)
        : name(n), group(g), address(a), recordBook(rb) {
    }

    void print() {
        cout << "Name: " << name.fullName << endl;
        cout << "Group: " << group.groupName << endl;
        cout << "Address: " << address.city << ", " << address.street << ", " << address.index << endl;
        recordBook.print();
    }
};

#endif 
