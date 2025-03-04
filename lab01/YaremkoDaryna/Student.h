#ifndef STUDENT_H
#define STUDENT_H
#include "Address.h"
#include "RecordBook.h"
#include "Utils.h"
#include <iostream>
using namespace std;

class Student {
private:
    string name, group;
    Address address;   
    RecordBook recordBook;
public:
    Student(string name = "", Address address = Address(), string group = "", RecordBook recordBook = RecordBook())
        : name(name), group(group), address(address), recordBook(recordBook) {}

    void display() const {
        cout << "Імʼя: " << name << endl;
        cout << "Група: " << group << endl;
        address.display();
        recordBook.display();
    }

    string getName() const { return name; }
    Address getAddress() const { return address; }
    string getGroup() const { return group; }
    RecordBook getRecordBook() const { return recordBook; }

    bool matchesCriteria(string searchValue, int searchType) const {
        switch (searchType) {
            case 1: return name == searchValue;
            case 2: return address.getCity() == searchValue;
            case 3: return group == searchValue;
            case 4: return recordBook.getRecordNumber() == searchValue;
            case 5: return recordBook.hasSubject(searchValue);
            case 6: return recordBook.hasSemester(stringToInt(searchValue));
            default: return false;
        }
    }
};
#endif
