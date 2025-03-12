#include "Functions.h"
#include "Group.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("students.txt");
    if (!file) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    Student* students = nullptr;
    int studentCount = 0;

    readFromFile(file, studentCount, students);
    file.close();

    if (studentCount == 0 || students == nullptr) {
        cout << "Жодного студента не знайдено." << endl;
        return 1;
    }

    Group* group = nullptr;

    firstMenu();

    int searchType;
    cin >> searchType;
    cin.ignore();

    if (searchType == 7) {
        string groupName;
        cout << "Введіть групу: ";
        getline(cin, groupName);

        Student* groupStudents = new Student[studentCount];
        int groupStudentCount = 0;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getGroup() == groupName) {
                groupStudents[groupStudentCount++] = students[i];
            }
        }

        if (groupStudentCount == 0) {
            cout << "Жодного студента не знайдено в " << groupName << "." << endl;
            delete[] groupStudents;
            delete[] students;
            return 1;
        }

        group = new Group(groupName, groupStudentCount, groupStudents);
        delete[] groupStudents;

        int groupChoice;
        do {
            secondMenu();
            cin >> groupChoice;
            cin.ignore();

            switch (groupChoice)
            {
            case 1:
            {
                Student student;
                cout << "Введіть дані про студента: ";
                cin >> student;
                group->addStudent(student);
                cout << "Студента додано." << endl;
                break;
            }
            case 2:
            {
                string studentName;
                cout << "Введіть ім'я студента: ";
                getline(cin, studentName);
                cout << endl;
                group->removeStudent(studentName);
                cout << "Студента видалено." << endl;
                break;
            }
            case 3:
            {
                cout << "Інформація про групу:" << endl;
                cout << *group << endl;
                break;
            }
            case 4:
            {
                Address address;
                cout << "Введіть адресу (поштовий індекс, місто, вулиця): ";
                cin >> address;
                cout << endl;
                group->searchByAddress(address);
                break;
            }
            case 5:
            {
                string recordNumber;
                cout << "Введіть номер залікової книжки: ";
                getline(cin, recordNumber);
                cout << endl;
                group->searchByZalikovkaNumber(recordNumber);
                break;
            }
            case 6:
            {
                string subjectName;
                cout << "Введіть назву предмета: ";
                getline(cin, subjectName);
                cout << endl;
                group->searchBySubject(subjectName);
                break;
            }
            case 0:
                cout << "Вихід із меню..." << endl;
                break;
            default:
                cout << "Неправильний вибір." << endl;
                break;
            }
        } while (groupChoice != 0);
    }
    else {
        string searchValue;
        cout << "Введіть варіант пошуку: ";
        getline(cin, searchValue);

        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].match(searchValue, searchType)) {
                cout << students[i] << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "Не знайдено студента із заданими критеріями." << endl;
        }

        if (group != nullptr) {
            delete group;
        }
        delete[] students;


        return 0;
    }
}