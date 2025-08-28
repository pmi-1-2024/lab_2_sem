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
    cout << "Меню:" << endl;
    cout << "1. За ім'ям" << endl;
    cout << "2. За містом (адресою)" << endl;
    cout << "3. За групою" << endl;
    cout << "4. За номером залікової книжки" << endl;
    cout << "5. За назвою предмету" << endl;
    cout << "6. За семестром" << endl;
    cout << "7. Меню групи" << endl;
    cout << "Введіть ваш вибір: ";
}

void menu2() {
    cout << "Меню групи:" << endl;
    cout << "1. Ввести назву групи" << endl;
    cout << "2. Додати студента" << endl;
    cout << "3. Видалити студента" << endl;
    cout << "4. Показати групу" << endl;
    cout << "5. Пошук за адресою" << endl;
    cout << "6. Пошук за номером залікової книжки" << endl;
    cout << "7. Пошук за назвою предмету" << endl;
    cout << "Введіть ваш вибір: ";
}

#endif