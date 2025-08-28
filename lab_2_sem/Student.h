#ifndef STUDENT_H
#define STUDENT_H
#include "Address.h"
#include "RecordBook.h"
#include <iostream>
using namespace std;

class Student {
private:
    string name, group;
    Address address;
    RecordBook recordBook;
public:
    Student() : name(""), group(""), address(Address("", "", "")), recordBook(RecordBook()) {}
    Student(string name, Address address, string group, RecordBook recordBook)
        : name(name), address(address), group(group), recordBook(recordBook) {}

    string getName() const { return name; }
    Address getAddress() const { return address; }
    string getGroup() const { return group; }
    RecordBook getRecordBook() const { return recordBook; }

    void display() const {
        cout << "Ім'я: " << name << "\nГрупа: " << group 
             << "\nАдреса: " << address << "\nЗалікова книжка: " << recordBook << endl;
    }

    bool matchesCriteria(string searchValue, int searchType) const {
        switch (searchType) {
            case 1: return name == searchValue;
            case 2: return address.getCity() == searchValue;
            case 3: return group == searchValue;
            case 4: return recordBook.getRecordNumber() == searchValue;
            case 5: return recordBook.hasSubject(searchValue);
            case 6: return recordBook.hasSemester(searchValue);
            default: return false;
        }
    }

    friend istream& operator>>(istream& is, Student& student) {
        is >> student.name >> student.address >> student.group >> student.recordBook;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name << " " << student.address << " " << student.group << " " << student.recordBook;
        return os;
    }
};

#endif