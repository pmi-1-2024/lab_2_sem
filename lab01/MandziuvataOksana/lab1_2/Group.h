#ifndef GROUP_H
#define GROUP_H

#include "Student.h"

class Group {
private:
    string name;
    Student* students;
    int studentCount;

public:
    Group(string n, Student* s, int count);
    ~Group();

    void addStudent(const Student& s);
    void removeStudent(const string& name);
    void searchByName(const string& name) const;
    void searchByGroupName(const string& groupName) const;
    void searchByRecordNumber(const string& recordNumber) const;
    void searchByAddress(const Address& addr) const;
    void printStudents() const;

    friend ostream& operator<<(ostream& out, const Group& g);
};

#endif

