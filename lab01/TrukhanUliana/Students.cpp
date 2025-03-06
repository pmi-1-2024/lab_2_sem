#include "Student.h"

Student::Student() : name(""), group(""), address(Address("", "", "")), recordBook(RecordBook("")) {}

Student::Student(string name, Address address, string group, RecordBook recordBook)
    : name(name), address(address), group(group), recordBook(recordBook) {
}

string Student::getName() const { return name; }
Address Student::getAddress() const { return address; }
string Student::getGroup() const { return group; }
RecordBook Student::getRecordBook() const { return recordBook; }

void Student::display() const {
    cout << "Name: " << name << "\nGroup: " << group
        << "\nAddress: " << address << "\nRecord Book: " << recordBook << endl;
}

bool Student::matchesCriteria(string searchValue, int searchType) const {
    switch (searchType) {
    case 1: // Пошук за іменем
        return name == searchValue;
    case 2: // Пошук за адресою (місто)
        return address.getCity() == searchValue;
    case 3: // Пошук за групою
        return group == searchValue;
    case 4: // Пошук за номером заліковки
        return recordBook.getRecordNumber() == searchValue;
    case 5: // Пошук за назвою предмета
        return recordBook.hasSubject(searchValue);
    case 6: { // Пошук за номером семестру
        return recordBook.hasSemester(searchValue);
    }
    default:
        return false;
    }
}

istream& operator>>(istream& is, Student& student) {
    is >> student.name >> student.address >> student.group >> student.recordBook;
    return is;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.name << " " << student.address << " " << student.group << " " << student.recordBook;
    return os;
}