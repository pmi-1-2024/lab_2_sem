#include "Student.h"

Student::Student() : name(""), group(""), address(Address("", "", "")), recordBook(RecordBook("")) {}
Student::Student(string name, Address address, string group, RecordBook recordBook)
    : name(name), address(address), group(group), recordBook(recordBook) {
}

void Student::display() const {
    cout << "Student: " << name << ", Group: " << group << endl;
    address.display();
    recordBook.display();
}

string Student::getName() const { return name; }
Address Student::getAddress() const { return address; }
string Student::getGroup() const { return group; }
RecordBook Student::getRecordBook() const { return recordBook; }

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