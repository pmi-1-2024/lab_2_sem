#ifndef GROUP_H
#define GROUP_H

#include <string>
#include "Student.h"

class Group {
private:
    string name;
    Student* students;
    int studentCount;

public:
    Group(string n, Student* s = nullptr, int count = 0);
    ~Group(); 
    Group(const Group& other); 
    Group& operator=(const Group& other); 
    Student& operator[](int index); 
    void addStudent(const Student& s);
    void removeStudent(const string& name);
    void searchByName(const string& name) const;
    void searchByGroupName(const string& groupName) const;
    void searchByRecordNumber(const string& recordNumber) const;
    void searchByAddress(const Address& addr) const;
    void printStudents() const;

    friend ostream& operator<<(ostream& out, const Group& g);
};

#endif // GROUP_H
