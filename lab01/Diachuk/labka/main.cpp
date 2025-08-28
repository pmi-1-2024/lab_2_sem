#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "SearchByName.h"
#include "SearchByGroup.h"
#include "SearchBySubject.h"
#include "SearchByResidence.h"
#include "SearchByGrade.h"
#include "SearchByPostalCode.h"

using namespace std;

const int MAX_STUDENTS = 100;

int readStudentsFromFile(const string& filename, Student students[], int maxStudents) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 0;
    }

    int count = 0;
    while (count < maxStudents && file >> students[count].name >> students[count].group >> students[count].subject
        >> students[count].residence >> students[count].grade >> students[count].postal_code) {
        count++;
    }
    file.close();
    return count;
}

void printStudentInfo(const Student& s) {
    s.print();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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
            searchByName(students, studentCount, input);
            break;
        case 2:
            cout << "Введіть групу для пошуку: ";
            cin >> input;
            searchByGroup(students, studentCount, input);
            break;
        case 3:
            cout << "Введіть предмет для пошуку: ";
            cin >> input;
            searchBySubject(students, studentCount, input);
            break;
        case 4:
            cout << "Введіть місце проживання для пошуку: ";
            cin >> input;
            searchByResidence(students, studentCount, input);
            break;
        case 5:
            cout << "Введіть оцінку для пошуку: ";
            cin >> grade;
            searchByGrade(students, studentCount, grade);
            break;
        case 6:
            cout << "Введіть поштовий індекс для пошуку: ";
            cin >> input;
            searchByPostalCode(students, studentCount, input);
            break;
        case 7:
            for (int i = 0; i < studentCount; i++) {
                printStudentInfo(students[i]);
            }
            break;
        }
    } while (choice != 0);

    return 0;
}
