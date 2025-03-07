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
            students[i].output();
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
        if (students[i].getGroup() == group) {
            students[i].output();
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in this group" << endl;
    }
}

void searchByAddress(Student* students, int count, const string& city, const string& street, int index) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (students[i].getAddress().city == city && students[i].getAddress().street == street && students[i].getAddress().houseNumber == houseNumber && students[i].getAddress().index == index) {
            students[i].output();
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
        if (students[i].getZalikovka().number == zalikNumber) {
            students[i].output();
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
        for (int j=0; j<students[i].getZalikovka().subjectCount; ++j) {
            if (students[i].getZalikovka().subjects[j].name == subjectName) {
                students[i].output();
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
        for (int j = 0; j < students[i].getZalikovka().subjectCount; ++j) {
            if (students[i].getZalikovka().subjects[j].semester == semester) {
                students[i].output();
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "No student found for this semester" << endl;
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
            Student* tempStudents = new Student[studentCount + 1];
            for (int i = 0; i < studentCount; ++i) {
                int(i = 0; i < studentCount; ++i) {
                    cout << "Enter data foor new student: " << endl;
                    tempStudents[studentCount].input();

                    delete[] students;
                    students = tempStudents;
                    ++studentCount;
                    saveToFile(students, studentCount);
                }
            }
        }
        else if (choice == 2) {
            string name;
            cout << "Enter student name to search: ";
            cin >> name;
            serchByName(students, studentCount, name);
        }
        else if (choice == 3) {
            string groupName;
            cout << "Enter group name to search: ";
            cin >> groupName;
            serchByGroup(students, studentCount, groupeName);
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