#include "Functions.h"
#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

void readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "���� �� ��������!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchStudentByName(const string& filename, const string& name) {
    ifstream file(filename);
    if (!file) {
        cout << "���� �� ��������!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == name) {
            found = true;
            cout << "�������� � ������ " << name << " ��������!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "�������� � ����� ��'�� �� ��������!" << endl;
    }

    file.close();
}

void searchStudentByGroup(const string& filename, const string& group) {
    ifstream file(filename);
    if (!file) {
        cout << "���� �� ��������!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == group) {
            found = true;
            cout << "�������� � ������ " << group << " ��������!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "�������� � ����� ������ �� ��������!" << endl;
    }

    file.close();
}
