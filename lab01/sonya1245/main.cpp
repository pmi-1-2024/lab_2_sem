#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

void saveToFile(Student* students, int count) {
    ofstream outFile("students.txt");
    for (int i = 0; i < count; ++i) {
        outFile << students[i].name << endl;
        outFile << students[i].group << endl;
        outFile << students[i].address.city << endl;
        outFile << students[i].address.street << endl
        outFile << students[i].address.houseNumber << endl;
        outFile << students[i].address.index << endl;
        outFile << students[i].zalikovka.number << endl;
        outFile << students[i].zalikovka.subjectCount << endl;
        for (int j = 0; j < students[i].zalikovka.subjectCount; ++j) {
            outFile << students[i].zalikovka.subjects[j].name << endl;
            outFile << students[i].zalikovka.subjects[j].semester << endl;
            outFile << students[i].zalikovka.subjects[j].grade << endl;
        }
    }
    outFile.close();
}

void searchByName(Student* students, int count, const string& name) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].name == name) {
            students[i].output();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found!" << endl;
    }
}

void searchByGroup(Student* students, int count, const string& group) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].group == group) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in this group!" << endl;
    }
}

void searchByAddress(Student* students, int count, const string& city, const string& street, int houseNumber, int index) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].address.city == city && students[i].address.street == street &&
            students[i].address.houseNumber == houseNumber && students[i].address.index == index) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with this address!" << endl;
    }
}

void searchByZalikovkaNumber(Student* students, int count, const string& zalikNumber) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].zalikovka.number == zalikNumber) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with this zalikovka number!" << endl;
    }
}

void searchBySubjectName(Student* students, int count, const string& subjectName) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < students[i].zalikovka.subjectCount; ++j) {
            if (students[i].zalikovka.subjects[j].name == subjectName) {
                students[i].output();
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No students found with this subject name!" << endl;
    }
}

void searchBySemester(Student* students, int count, int semester) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < students[i].zalikovka.subjectCount; ++j) {
            if (students[i].zalikovka.subjects[j].semester == semester) {
                students[i].output();
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No students found for this semester!" << endl;
    }
}

int main() {
    const int MAX_STUDENTS = 100;
    Student* students = new Student[MAX_STUDENTS];
    int studentCount = 0;

    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add new student\n";
        cout << "2. Search by student name\n";
        cout << "3. Search by group name\n";
        cout << "4. Search by address\n";
        cout << "5. Search by zalikovka number\n";
        cout << "6. Search by subject name\n";
        cout << "7. Search by semester\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student* tempStudents = new Student[studentCount + 1];
            for (int i = 0; i < studentCount; ++i) {
                tempStudents[i] = students[i];
            }
            cout << "Enter data for new student:\n";
            tempStudents[studentCount].input();

            delete[] students;
            students = tempStudents;

            ++studentCount;

            saveToFile(students, studentCount);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter student name to search: ";
            cin >> name;
            searchByName(students, studentCount, name);
        }
        else if (choice == 3) {
            string groupName;
            cout << "Enter group name to search: ";
            cin >> groupName;
            searchByGroup(students, studentCount, groupName);
        }
        else if (choice == 4) {
            string city, street;
            int houseNumber, index;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter street: ";
            cin >> street;
            cout << "Enter house number: ";
            cin >> houseNumber;
            cout << "Enter index: ";
            cin >> index;
            searchByAddress(students, studentCount, city, street, houseNumber, index);
        }
        else if (choice == 5) {
            string zalikNumber;
            cout << "Enter zalikovka number: ";
            cin >> zalikNumber;
            searchByZalikovkaNumber(students, studentCount, zalikNumber);
        }
        else if (choice == 6) {
            string subjectName;
            cout << "Enter subject name: ";
            cin >> subjectName;
            searchBySubjectName(students, studentCount, subjectName);
        }
        else if (choice == 7) {
            int semester;
            cout << "Enter semester: ";
            cin >> semester;
            searchBySemester(students, studentCount, semester);
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