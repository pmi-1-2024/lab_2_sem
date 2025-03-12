#include <windows.h>
#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = readStudentsFromFile("students.txt", students, MAX_STUDENTS);

    if (studentCount == 0) {
        cout << "Немає студентів у файлі!" << endl;
        return 1;
    }

    int choice;
    string input;
    double grade;

    do {
        cout << "\nМеню пошуку студентів за критерієм:" << endl;
        cout << "1. Пошук за ім'ям" << endl;
        cout << "2. Пошук за групою" << endl;
        cout << "3. Пошук за предметом" << endl;
        cout << "4. Пошук за місцем проживання" << endl;
        cout << "5. Пошук за оцінкою" << endl;
        cout << "6. Пошук за поштовим індексом" << endl;
        cout << "7. Вивести всіх студентів" << endl;
        cout << "0. Вийти" << endl;
        cout << "Виберіть критерій пошуку (0-7): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть ім'я для пошуку: ";
            cin >> input;
            name(students, studentCount, input);
            break;
        case 2:
            cout << "Введіть групу для пошуку: ";
            cin >> input;
            group(students, studentCount, input);
            break;
        case 3:
            cout << "Введіть предмет для пошуку: ";
            cin >> input;
            subject(students, studentCount, input);
            break;
        case 4:
            cout << "Введіть місце проживання для пошуку: ";
            cin >> input;
            address(students, studentCount, input);
            break;
        case 5:
            cout << "Введіть оцінку для пошуку: ";
            cin >> grade;
            grade(students, studentCount, grade);
            break;
        case 6:
            cout << "Введіть поштовий індекс для пошуку: ";
            cin >> input;
            postl(students, studentCount, input);
            break;
        case 7:
            cout << "Всі студенти:" << endl;
            for (int i = 0; i < studentCount; ++i) {
                printStudentInfo(students[i]);
            }
            break;
        case 0:
            cout << "Вихід з програми." << endl;
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}
