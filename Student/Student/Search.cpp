#include "Search.h"
#include <iostream>

void findByName(Student* students, int count, string name) {
    bool found = false;
    cout << "����� �� ��'��: " << name << endl;
    for (int i = 0; i < count; i++) {
        cout << "��������� �: " << students[i].getName() << endl;
        if (students[i].getName() == name) {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}

void findByGroup(Student* students, int count, string group) {
    bool found = false;
    cout << "����� �� ������: " << group << endl;
    for (int i = 0; i < count; i++) {
        cout << "��������� �: " << students[i].getGroup() << endl;
        if (students[i].getGroup() == group) {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}

void findByZalik(Student* students, int count, int zalikNumber) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].getZalik().getId() == zalikNumber) {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}

void findByAdress(Student* students, int count, string addressPart) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        Adress addr = students[i].getAdress();
        string fullAddress = addr.getCity() + " " + addr.getHouse();
        if (fullAddress.find(addressPart) != string::npos) {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}

void findBySubject(Student* students, int count, string subjectName) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].getZalik().findSubjectByName(subjectName).getName() != "") {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}

void findBySem(Student* students, int count, int semester) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].getZalik().findSubjectBySemester(semester).getName() != "") {
            students[i].print();
            found = true;
        }
    }
    if (!found) cout << "������� �������� �� ��������!" << endl;
}


