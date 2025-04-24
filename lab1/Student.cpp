#include "Student.h"

Student::Student() : name(""), group("") {}

Student::Student(string n, Address addr, string gr, RecordBook rb)
    : name(n), address(addr), group(gr), recordBook(rb) {}

string Student::GetName() const
{
    return name;
}

string Student::GetGroup() const
{
    return group;
}

Address Student::GetAddress() const
{
    return address;
}

string Student::GetRecordNumber() const
{
    return recordBook.GetNumber();
}


istream& operator>>(istream& in, Student& s) {
    cout << "Enter student name: ";
    in >> s.name;
    cout << "Enter address:\n";
    in >> s.address;
    cout << "Enter group: ";
    in >> s.group;
    cout << "Enter record book details:\n";
    in >> s.recordBook;
    return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
    out << "\nName: " << s.name;
    out << "\nGroup: " << s.group;
    out << "\nData of address: " << s.address;
    out << "\nData of zalikovka: " << s.recordBook;
    return out;
}
