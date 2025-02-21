#pragma once
#include <string>
#include "Address.h"
#include "RecordBook.h"

using namespace std;

class Student {
public:
    string name;
    string groupName;
    Address address;
    RecordBook recordBook;
    Student(string name = "", string groupName = "", Address address = Address(), RecordBook recordBook = RecordBook());
    void input();
    void output() const;
};
