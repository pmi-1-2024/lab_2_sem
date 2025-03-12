#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

int readStudentsFromFile(const string& filename, Student students[], int maxStudents) {
    ifstream file(filename);
    if (!file) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line) && count < maxStudents) {
        size_t pos = 0;
        Student s;

        pos = line.find(" ");
        s.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(" ");
        s.group = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(" ");
        s.subject = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(" ");
        s.residence = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(" ");
        s.grade = stod(line.substr(0, pos));
        line.erase(0, pos + 1);

        s.postal_code = line;

        students[count++] = s;
    }
    file.close();
    return count;
}

void printStudentInfo(const Student& s) {
    cout << "Ім'я: " << s.name << ", Група: " << s.group
        << ", Предмет: " << s.subject << ", Місце проживання: " << s.residence
        << ", Оцінка: " << s.grade << ", Поштовий індекс: " << s.postal_code << endl;
}
