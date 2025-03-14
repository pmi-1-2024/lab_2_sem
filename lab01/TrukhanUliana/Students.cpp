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
    case 1: // ����� �� ������
        return name == searchValue;
    case 2: // ����� �� ������� (����)
        return address.getCity() == searchValue;
    case 3: // ����� �� ������
        return group == searchValue;
    case 4: // ����� �� ������� ��������
        return recordBook.getRecordNumber() == searchValue;
    case 5: // ����� �� ������ ��������
        return recordBook.hasSubject(searchValue);
    case 6: { // ����� �� ������� ��������
        return recordBook.hasSemester(searchValue);
    }
    default:
        return false;
    }
}