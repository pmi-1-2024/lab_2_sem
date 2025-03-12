#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "Group.h"
#include "File.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    writeStudentsToFile("students.txt");

    int studentCount;
    Student* students = nullptr;

    readStudentsFromFile("students.txt", students, studentCount);

    Group groups[4] = {
        Group("��-43"),
        Group("��-11"),
        Group("���-12"),
        Group("���-24")
    };

    for (int i = 0; i < studentCount; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (students[i].getGroup() == groups[j].getName()) {
                groups[j].addStudent(students[i]);
            }
        }
    }

    handleMenu(students, studentCount, groups, 4);

    delete[] students;

    return 0;
}

