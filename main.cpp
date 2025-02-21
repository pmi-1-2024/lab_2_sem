#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> 
#include <limits>


void loadStudents(vector<Student>& students) {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (true) {
        string name, zip, city, street, group, recordNumber;
        int numSubjects;

        if (!getline(file, name) || name.empty()) break;  // Перевірка, щоб уникнути порожнього рядка
        file >> zip >> city >> ws;
        getline(file, street);
        file >> group >> recordNumber >> numSubjects;

        Address addr(zip, city, street);
        RecordBook rb(recordNumber);

        for (int i = 0; i < numSubjects; i++) {
            string subjectName;
            int semester;
            double grade;
            file >> ws;
            getline(file, subjectName);
            file >> semester >> grade;
            rb.addSubject(Subject(subjectName, semester, grade));
        }

        students.push_back(Student(name, addr, group, rb));
    }

    file.close();
    cout << "Loaded " << students.size() << " students from file.\n"; // Дебаг
}




// Додаємо бібліотеку для numeric_limits

#include <limits> // Для cin.ignore()

void searchStudent(const vector<Student>& students) {
    string query;
    cout << "Enter student name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера перед введенням
    getline(cin, query);

    for (const auto& student : students) {
        cout << "DEBUG: Searching [" << query << "] vs [" << student.name << "]" << endl;
        if (student.name == query) {
            student.display();
            return;
        }
    }
    cout << "Student not found." << endl;
}



int main() {
    vector<Student> students;
    loadStudents(students);

    if (students.empty()) {
        cout << "No students loaded. Check students.txt file!\n";
        return 1;
    }

    while (true) {
        cout << "\nMenu:\n1. Search student\n2. Exit\nYour choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) { // Якщо введено не число, скидаємо стан
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            searchStudent(students);
        }
        else if (choice == 2) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}

