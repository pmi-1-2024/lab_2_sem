#include "Student.h"
Student::Student() :name("noname"), group("nogroup"), address(), zalik(){}
Student::Student(string n,string g,Address a,Zalikovka z) : name(n), group(g), address(a), zalik(z) {}

string Student::getName() const {
    return name;
}

string Student::getGroup() const { 
    return group; 
}

string Student::getId() const { 
    return zalik.getId();
}

string Student::getAddress() const { 
    return address.getFullAddress();
}

void Student::display(ostream& os) const {
    cout << "Student: " << name << ", Group: " << group << endl;
    address.display(os);
    zalik.display(os);
}

void Student::read(istream& is)
{
    is >> this->name >> this->group >> this->address >> this->zalik;
}

istream& operator>>(istream& is, Student& s)
{
    s.read(is);
    return is;
}
ostream& operator<<(ostream& os, const Student& s) { // Виправлено const
    s.display(os);
    return os;
}