#include "Functions.h"
#include <iostream>
using namespace std;


void readFromFile(ifstream& file, int& studentCount, Student*& students) {
    if (!file.is_open()) {
        cout << "Помилка: файл не можливо відкрити!" << endl;
        return;
    }

    file >> studentCount;

    if (students != nullptr) {
        delete[] students;
    }

    students = new Student[studentCount];

    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
}


void firstMenu() {
    cout << "Меню пошуку:" << endl;
    cout << "1. За ім'ям" << endl;
    cout << "2. За адресою" << endl;
    cout << "3. За групою" << endl;
    cout << "4. За номером залікової книжки" << endl;
    cout << "5. За предметом" << endl;
    cout << "6. За семестром" << endl;
    cout << "7. *Меню академічної групи*" << endl;
    cout << "Ваш вибір: ";
}

void secondMenu() {
    cout << "Меню академічної групи:" << endl;
    cout << "1. Показати групу" << endl;
    cout << "2. Додати студента" << endl;
    cout << "3. Видалити студента" << endl;
    cout << "4. Пошук за адресою" << endl;
    cout << "5. Пошук за номером залікової книжки" << endl;
    cout << "6. Пошук за предметом" << endl;
    cout << "0. Вихід" << endl;
    cout << "Ваш вибір: ";
}
