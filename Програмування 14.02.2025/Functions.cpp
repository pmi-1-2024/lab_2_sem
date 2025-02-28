#include "Functions.h"
#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

void readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchStudentByName(const string& filename, const string& name) {
    ifstream file(filename);
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == name) {
            found = true;
            cout << "Студента з іменем " << name << " знайдено!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Студента з таким ім'ям не знайдено!" << endl;
    }

    file.close();
}

void searchStudentByGroup(const string& filename, const string& group) {
    ifstream file(filename);
    if (!file) {
        cout << "Файл не знайдено!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line == group) {
            found = true;
            cout << "Студента з групою " << group << " знайдено!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "Студента з такою групою не знайдено!" << endl;
    }

    file.close();
}
