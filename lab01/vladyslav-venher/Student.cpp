#include "Student.h"
#include "Address.h"
#include "Zalikovka.h"
using namespace std;

Student::Student() : name(""), group(""), address(Address("", "", "")), zalikovka(Zalikovka()) {}
Student::Student(string name, Address address, string group, Zalikovka zalikovka)
    : name(name), address(address), group(group), zalikovka(zalikovka) {
}

string Student::getName() const { return name; }
Address Student::getAddress() const { return address; }
string Student::getGroup() const { return group; }
Zalikovka Student::getZalikovka() const { return zalikovka; }

bool Student::match(string searchValue, int searchType) const {
    switch (searchType) {
    case 1: 
        return name == searchValue;
    case 2: 
        return address.getCity() == searchValue;
    case 3:
        return group == searchValue;
    case 4:
        return zalikovka.getZalikovkaNumber() == searchValue;
    case 5: 
        return zalikovka.hasSubject(searchValue);
    case 6: { 
        return zalikovka.hasSemester(searchValue);
    }
    default:
        return false;
    }
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Ім'я: " << student.name << "\n"
        << "Адреса: " << student.address << "\n"
        << "Група: " << student.group << "\n"
        << "Заліковка: " << student.zalikovka;
    return os;
}

istream& operator>>(istream& is, Student& student) {
    getline(is, student.name); 
    is >> student.address;     
    is.ignore();                
    getline(is, student.group); 
    is >> student.zalikovka;    
    return is;
}