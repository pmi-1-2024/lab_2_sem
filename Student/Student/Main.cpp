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
    file << "79210\n";
    file << "Мукачево\n";
    file << "Сихівська 5\n";
    file << "ПМк-12\n";
    file << "11232 3\n";
    file << "Дискретна математика\n";
    file << "5 17.0\n";
    file << "Рисунок\n";
    file << "2 55.0\n";
    file << "Французька\n";
    file << "4 81.0\n";
    file << "Мартін Безе\n";
    file << "21231\n";
    file << "Франкфурт\n";
    file << "Людінвауськ 61\n";
    file << "НІ-45\n";
    file << "91312 2\n";
    file << "Матеріалознавство\n";
    file << "6 32.0\n";
    file << "Малювання\n";
    file << "2 12.0\n";
    file << "Олег Франк\n";
    file << "30120\n";
    file << "Біла Церква\n";
    file << "Ромова 87\n";
    file << "ЗІм-23\n";
    file << "67890 4\n";
    file << "Фізкультура\n";
    file << "1 75.0\n";
    file << "Фізика\n";
    file << "6 21.0\n";
    file << "Хімічні основи\n";
    file << "3 28.0\n";
    file << "Англіська\n";
    file << "4 56.0\n";

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
        zalik1.setSubject(0, Subject("Математичний Аналіз", 5, 91.0f));
        zalik1.setSubject(1, Subject("Фізика та електроніка", 2, 43.0f));
        zalik1.setSubject(2, Subject("Хімічні основи", 3, 82.0f));
        students[0] = Student("Андрій Труба", Adress(79070, "Львів", "Вокзальна 6"), "ХЕ-43", zalik1);

        Zalik zalik2(56741, 2);
        zalik2.setSubject(0, Subject("Біотехнології", 5, 95.0f));
        zalik2.setSubject(1, Subject("Історія", 1, 20.0f));
        students[1] = Student("Марія Лаванда", Adress(20220, "Київ", "Моршинська 2"), "БІ-11", zalik2);

        Zalik zalik3(86933, 4);
        zalik3.setSubject(0, Subject("Математичний аналіз", 1, 55.0f));
        zalik3.setSubject(1, Subject("Фізика та електроніка", 4, 22.0f));
        zalik3.setSubject(2, Subject("Хімічні основи", 1, 23.0f));
        zalik3.setSubject(3, Subject("Англіська", 3, 65.0f));
        students[2] = Student("Антон Ракєта", Adress(32030, "Одеса", "Єврейська 21"), "ПМі-22", zalik3);

        handleMenu(students, studentCount);

        delete[] students;
    }

    return 0;
}
