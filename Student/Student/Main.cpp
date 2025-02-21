#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "File.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void writeStudentsToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    file << "3\n";
    file << "Іван Малина\n";
    file << "28310\n";
    file << "Кремень\n";
    file << "Цибулева 23\n";
    file << "ПМк-12\n";
    file << "32553 3\n";
    file << "Географія\n";
    file << "3 32.0\n";
    file << "Філософія\n";
    file << "3 67.0\n";
    file << "Геополітика\n";
    file << "6 23.0\n";
    file << "Олена Свавілко\n";
    file << "12454\n";
    file << "Миколаїв\n";
    file << "Староєврейська 10\n";
    file << "ГАр-24\n";
    file << "43218 2\n";
    file << "Хірургічні основи\n";
    file << "2 21.0\n";
    file << "Історія медецини\n";
    file << "6 23.0\n";
    file << "Лава Гарнір\n";
    file << "30232\n";
    file << "Житомир\n";
    file << "Сан-Тропеська 90\n";
    file << "ІН-23\n";
    file << "32421 4\n";
    file << "Інтелектуальні системи\n";
    file << "4 46.0\n";
    file << "Програмування\n";
    file << "1 23.0\n";
    file << "Біохімія\n";
    file << "5 12.0\n";
    file << "Англіська\n";
    file << "4 81.0\n";

    file.close();
    cout << "Дані успішно записані у файл " << filename << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    writeStudentsToFile("students.txt");

    int studentCount;
    Student* students = nullptr;

    readStudentsFromFile("students.txt", students, studentCount);

    if (students != nullptr) {
        handleMenu(students, studentCount);
        delete[] students;
    }
    else {
        cout << "Не вдалося зчитати дані студентів з файлу." << endl;

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

        handleMenu(students, studentCount);

        delete[] students;
    }

    return 0;
}
