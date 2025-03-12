#include "Student.h"
#include "Group.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void saveToFile(Student* students, int count) {
    ofstream outFile("students.txt");
    for (int i = 0; i < count; ++i) {
        outFile << students[i] << endl;
    }
    outFile.close();
}

void searchByName(Student* students, int count, const string& name) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getName() == name) {
            cout << students[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found" << endl;
    }
}

void searchByGroup(Student* students, int count, const string& group) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getGroupName() == group) {
            cout << students[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in this group" << endl;
    }
}

void searchByAddress(Student* students, int count, const Address& address) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getAddress() == address) {
            cout << students[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with this address" << endl;
    }
}

void searchByZalikovkaNumber(Student* students, int count, const string& zalikNumber) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getZalikovkaNumber().getNumber == zalikNumber) {
            cout << students[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with this zalikovka number" << endl;
    }
}

void searchBySubjectName(Student* students, int count, const string& subjectName) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        const Zalikovka& z = students[i].getZalikovkaNumber();
        for (int j = 0; j < z.getSubjectCount(); ++j) {
            if (z.getSubjects()[j].name == subjectName) {
                cout << students[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No student found with this subject name" << endl;
    }
}

void searchBySemester(Student* students, int count, int semester) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        const Zalikovka& z = students[i].getZalikovkaNumber();
        for (int j = 0; j < z.getSubjectCount(); ++j) {
            if (z.getSubjects()[j].semester == semester) {
                cout << students[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No student found for this semester" << endl;
    }
}

void addStudent(Student*& students, int& studentCount) {
    Student* tempStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; ++i) {
        tempStudents[i] = students[i];
    }
    cout << "Enter data for new student: " << endl;
    cin >> tempStudents[studentCount];
    delete[] students;
    students = tempStudents;
    ++studentCount;
    saveToFile(students, studentCount);
}

void searchStudent(Student* students, int studentCount, int choice) {
    string input;
    Address address;
    int semester;
    switch (choice) {
        case 2:
            cout << "Enter student name to search: ";
            cin >> ws;
            getline(cin, input);
            searchByName(students, studentCount, input);
            break;
        case 3:
            cout << "Enter group name to search: ";
            cin >> ws;
            getline(cin, input);
            searchByGroup(students, studentCount, input);
            break;
        case 4:
            cout << "Enter address details:\n";
            cin >> address;
            searchByAddress(students, studentCount, address);
            break;
        case 5:
            cout << "Enter zalikovka number: ";
            cin >> ws;
            getline(cin, input);
            searchByZalikovkaNumber(students, studentCount, input);
            break;
        case 6:
            cout << "Enter subject name: ";
            cin >> ws;
            getline(cin, input);
            searchBySubjectName(students, studentCount, input);
            break;
        case 7:
            cout << "Enter semester: ";
            cin >> semester;
            searchBySemester(students, studentCount, semester);
            break;
        default:
            cout << "Invalid choice" << endl;
    }
}

int main() {
    const int max_students = 100;
    Student* students = new Student[max_students];
    int studentCount = 0;

    int choice;
    while (true) {
        cout << "Menu" << endl;
        cout << "1. Add new student" << endl;
        cout << "2. Search by student name" << endl;
        cout << "3. Search by group name" << endl;
        cout << "4. Search by address" << endl;
        cout << "5. Search by zalikovka number" << endl;
        cout << "6. Search by subject name" << endl;
        cout << "7. Search by semester" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1) {
            addStudent(students, studentCount);
        }
        else if (choice >= 2 && choice <= 7) {
            searchStudent(students, studentCount, choice);
        }
        else if (choice == 8) {
            break;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }
    delete[] students;
    return 0;
}