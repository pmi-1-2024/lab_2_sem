#include <iostream>
#include "Student_Manager.h"
#include <windows.h>

using namespace std;

void menu() {
    cout << "\nМеню:" << endl;
    cout << "1) Добавити студента" << endl;
    cout << "2) Видалити студента" << endl;
    cout << "3) Знайти студента" << endl;
    cout << "4) Оновити інформацію" << endl;
    cout << "5) Показати всіх студентів" << endl;
    cout << "0) Вийти" << endl;
    cout << "Ваш вибір: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Лабораторна робота 4" << endl;
    cout << "Виконав студент групи ПМІ11 Дячук Ігор" << endl << endl;
    cout << "Інформація по коду:" << endl;
    cout << "Цей код реалізує систему для управління студентами за допомогою динамічних структур даних." << endl;

    Student_Manager manager;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Student student;
            cin >> student;
            manager.addStudent(student);
            cout << "Студента добавлено.\n";
            break;
        }
        case 2: {
            Student student;
            cin >> student;
            manager.removeStudent(student);
            break;
        }
        case 3: {
            Student student;
            cin >> student;
            manager.findStudent(student);
            break;
        }
        case 4: {
            Student oldStudent, newStudent;
            cout << "Введіть старі дані студента:\n";
            cin >> oldStudent;
            cout << "Введіть нові дані студента:\n";
            cin >> newStudent;
            manager.updateStudent(oldStudent, newStudent);
            break;
        }
        case 5:
            manager.displayAll();
            break;
        case 0:
            cout << "Вихід." << endl;
            break;
        default:
            cout << "Попробуйте ще раз" << endl;
        }
    } while (choice != 0);

    return 0;
}