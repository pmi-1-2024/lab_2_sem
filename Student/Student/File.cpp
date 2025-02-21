#include "File.h"
#include <fstream>
#include <iostream>

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
        string name, city, house, group;
        unsigned index, id, subjCount;
        file >> ws;
        getline(file, name);
        file >> index >> ws;
        getline(file, city);
        file >> ws;
        getline(file, house);
        file >> ws;
        getline(file, group);
        file >> id >> subjCount;

        if (file.fail()) {
            cout << "Помилка зчитування даних студента." << endl;
            delete[] students;
            students = nullptr;
            return;
        }

        Zalik zalik(id, subjCount);
        for (unsigned j = 0; j < subjCount; ++j) {
            string subjName;
            unsigned sem;
            float grade;
            file >> ws;
            getline(file, subjName);
            file >> sem >> grade;

            if (file.fail()) {
                cout << "Помилка зчитування даних предмета." << endl;
                delete[] students;
                students = nullptr;
                return;
            }

            zalik.setSubject(j, Subject(subjName, sem, grade));
        }

        students[i] = Student(name, Adress(index, city, house), group, zalik);
    }

    file.close();
}

