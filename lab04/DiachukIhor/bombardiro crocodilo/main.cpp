#include <iostream>
#include "Student_Manager.h"
#include <windows.h>

using namespace std;

void menu() {
    cout << "\nМеню:" << endl;
    cout << "1)Добавити студента" << endl;
    cout << "2)Видалити студента" << endl;
    cout << "3)Знайти студента" << endl;
    cout << "4)Оновити інформацію" << endl;
    cout << "5)Показати всіх студентів" << endl;
    cout << "0)Вийти" << endl;
    cout << "Ваш вибір: ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    cout << "Лабораторна робота 4" << endl;
    cout << "Виконав студент групи ПМІ11 Дячук Ігор" << endl << endl;
    cout << "інформація по коду:" << endl;
    cout << "Цей код реалізує систему для управління студентами за допомогою динамічних структур даних." << endl;

    Student_Manager manager;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string name;
            int id;
            cout << "Введіть Ім'я студента: ";
            getline(cin, name);
            cout << "Введіть ID студента: ";
            cin >> id;
            manager.addStudent(Student(name, id));
            cout << "Студента добавлено.\n";
            break;
        }
        case 2: {
            string name;
            int id;
            cout << "Введіть Ім'я вже добавленого студента: ";
            getline(cin, name);
            cout << "Введіть ID студента: ";
            cin >> id;
            manager.removeStudent(Student(name, id));
            break;
        }
        case 3: {
            string name;
            int id;
            cout << "Введіть Ім'я студента: ";
            getline(cin, name);
            cout << "Введіть ID студента: ";
            cin >> id;
            manager.findStudent(Student(name, id));
            break;
        }
        case 4: {
            string oldName, newName;
            int oldId, newId;
            cout << "Введіть Ім'я студента: ";
            getline(cin, oldName);
            cout << "Введіть ID студента: ";
            cin >> oldId;
            cin.ignore();
            cout << "Введіть нове Ім'я студента: ";
            getline(cin, newName);
            cout << "Введіть новий ID студента: ";
            cin >> newId;
            manager.updateStudent(Student(oldName, oldId), Student(newName, newId));
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
