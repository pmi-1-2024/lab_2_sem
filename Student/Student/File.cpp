#include "File.h"
#include "Group.h"
#include <fstream>
#include <iostream>
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

void readStudentsFromFile(const string& filename, Student*& students, int& count) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не вдалося відкрити файл!" << endl;
        return;
    }

    file >> count;
    if (count <= 0) {
        cout << "Невірний формат файлу або кількість студентів." << endl;
        return;
    }

    students = new Student[count];
    if (students == nullptr) {
        cout << "Не вдалося виділити пам'ять для студентів." << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        file >> students[i];
        if (file.fail()) {
            cout << "Помилка зчитування даних студента." << endl;
            delete[] students;
            students = nullptr;
            return;
        }
    }

    file.close();
}
