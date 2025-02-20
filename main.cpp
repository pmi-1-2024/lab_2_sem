#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;

void saveToFile(Student* students, int count) {
    ofstream outFile("students.txt");
    for (int i = 0; i < count; ++i) {
        outFile << students[i].name << endl;
        outFile << students[i].groupName << endl;
        outFile << students[i].address.city << endl;
        outFile << students[i].address.street << endl;
        outFile << students[i].address.houseNumber << endl;
        outFile << students[i].recordBook.number << endl;
        outFile << students[i].recordBook.subjectCount << endl;
        for (int j = 0; j < students[i].recordBook.subjectCount; ++j) {
            outFile << students[i].recordBook.subjects[j].name << endl;
            outFile << students[i].recordBook.subjects[j].semester << endl;
            outFile << students[i].recordBook.subjects[j].grade << endl;
        }
    }
    outFile.close();
}

int loadFromFile(Student*& students) {
    ifstream inFile("students.txt");
    int count = 0;
    while (!inFile.eof()) {
        string name, groupName, city, street, recordNumber, subjectName;
        int houseNumber, subjectCount, semester, grade;

        inFile >> name;
        if (name.empty()) break;
        inFile >> groupName >> city >> street >> houseNumber >> recordNumber >> subjectCount;

        Address address(city, street, houseNumber);
        RecordBook recordBook(recordNumber, subjectCount);
        recordBook.subjects = new Subject[subjectCount];

        for (int i = 0; i < subjectCount; ++i) {
            inFile >> subjectName >> semester >> grade;
            recordBook.subjects[i] = Subject(subjectName, semester, grade);
        }

        Student* tempStudents = new Student[count + 1];
        for (int i = 0; i < count; ++i) {
            tempStudents[i] = students[i];
        }
        tempStudents[count] = Student(name, groupName, address, recordBook);

        delete[] students;
        students = tempStudents;

        ++count;
    }
    inFile.close();
    return count;
}


void searchByName(Student* students, int count, const string& name) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].name == name) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "Student with name '" << name << "' not found!" << endl;
    }
}


void searchByGroup(Student* students, int count, const string& groupName) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].groupName == groupName) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in group '" << groupName << "'!" << endl;
    }
}


int main() {
    Student* students = nullptr;
    int studentCount;


    int loadedCount = loadFromFile(students);

    cout << "\nLoaded student data from file:\n";
    for (int i = 0; i < loadedCount; ++i) {
        students[i].output();
    }

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add new student\n";
        cout << "2. Search by student name\n";
        cout << "3. Search by group name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            Student* tempStudents = new Student[loadedCount + 1];
            for (int i = 0; i < loadedCount; ++i) {
                tempStudents[i] = students[i];
            }
            cout << "Enter data for new student:\n";
            tempStudents[loadedCount].input();

            delete[] students;
            students = tempStudents;

            ++loadedCount;

            saveToFile(students, loadedCount);

        }
        else if (choice == 2) {
            string name;
            cout << "Enter student name to search: ";
            cin >> name;
            searchByName(students, loadedCount, name);

        }
        else if (choice == 3) {
            string groupName;
            cout << "Enter group name to search: ";
            cin >> groupName;
            searchByGroup(students, loadedCount, groupName);

        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    delete[] students;
    return 0;
}
