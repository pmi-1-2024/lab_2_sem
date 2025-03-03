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

    if (students == nullptr) {
        cout << "Не вдалося зчитати дані студентів з файлу. Ініціалізація студентів вручну." << endl;

        studentCount = 3;
        students = new Student[studentCount];

        Zalik zalik1(73528, 3);
        zalik1.setSubject(0, Subject("Математичний Аналіз", 1, 90.0f));
        zalik1.setSubject(1, Subject("Фізика та електроніка", 2, 85.0f));
        zalik1.setSubject(2, Subject("Хімічні основи", 1, 88.0f));
        students[0] = Student("Андрій Труба", Adress(79070, "Львів", "Вокзальна 6"), "ХЕ-43", zalik1);

        Zalik zalik2(56741, 2);
        zalik2.setSubject(0, Subject("Біотехнології", 1, 92.0f));
        zalik2.setSubject(1, Subject("Історія", 2, 80.0f));
        students[1] = Student("Марія Лаванда", Adress(20220, "Київ", "Моршинська 2"), "БІ-11", zalik2);

        Zalik zalik3(86933, 4);
        zalik3.setSubject(0, Subject("Математичний аналіз", 1, 75.0f));
        zalik3.setSubject(1, Subject("Фізика та електроніка", 2, 82.0f));
        zalik3.setSubject(2, Subject("Хімічні основи", 1, 78.0f));
        zalik3.setSubject(3, Subject("Англіська", 2, 85.0f));
        students[2] = Student("Антон Ракєта", Adress(32030, "Одеса", "Єврейська 21"), "ПМі-22", zalik3);
    }

    Group groups[4] = {
        Group("ХЕ-43"),
        Group("БІ-11"),
        Group("ПМк-12"),
        Group("ГАр-24")
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

