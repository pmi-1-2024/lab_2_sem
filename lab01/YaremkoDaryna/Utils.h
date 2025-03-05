#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <fstream>
#include "Group.h"
using namespace std;

void readFromFile(ifstream& file, int& studentCount, Student*& students) {
    if (!file.is_open()) return;
    file >> studentCount;
    students = new Student[studentCount];
    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
}

void menu1() {
    cout << "Menu:" << endl;
    cout << "1. By name" << endl;
    cout << "2. By city(address)" << endl;
    cout << "3. By group" << endl;
    cout << "4. By recordbook number" << endl;
    cout << "5. By subject name" << endl;
    cout << "6. By semester" << endl;
    cout << "7. Group menu" << endl;
    cout << "Enter a number: ";
}

void menu2() {
    cout << "Group menu:" << endl;
    cout << "1. Enter group menu" << endl;
    cout << "2. Add student" << endl;
    cout << "3. Delete student" << endl;
    cout << "4. Show group" << endl;
    cout << "5. Search by address" << endl;
    cout << "6. Search by recordbook number" << endl;
    cout << "7. Search by subject" << endl;
    cout << "Enter a number: ";
}

#endif