#include "Student.h"
#include "Search.h"
#include "Menu.h"
#include "File.h"
#include <iostream>
#include <fstream> // Ensure this is included
#include <Windows.h>
using namespace std;

void writeStudentsToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    file << "3\n";
    file << "Іван Петров\n";
    file << "79000\n";
    file << "Львів\n";
    file << "Головна 10\n";
    file << "ІП-12\n";
    file << "12345 3\n";
    file << "Math\n";
    file << "1 90.0\n";
    file << "Physics\n";
    file << "2 85.0\n";
    file << "Chemistry\n";
    file << "1 88.0\n";
    file << "Марія Коваленко\n";
    file << "2000\n";
    file << "Київ\n";
    file << "Шевченка 5\n";
    file << "ІТ-22\n";
    file << "54321 2\n";
    file << "Biology\n";
    file << "1 92.0\n";
    file << "History\n";
    file << "2 80.0\n";
    file << "Олег Іванов\n";
    file << "3000\n";
    file << "Одеса\n";
    file << "Дерибасівська 7\n";
    file << "ПМ-31\n";
    file << "67890 4\n";
    file << "Math\n";
    file << "1 75.0\n";
    file << "Physics\n";
    file << "2 82.0\n";
    file << "Chemistry\n";
    file << "1 78.0\n";
    file << "English\n";
    file << "2 85.0\n";

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
