#include "Student.h"
#include "Features.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student students[100];
    int studentCount = 0;

    readFile(file, studentCount, students);

    menu();

    int searchType;
    cin >> searchType;

    cout << "Enter search term: ";
    string searchValue;
    cin >> searchValue;

    bool found = false; 
    for (int i = 0; i < studentCount; i++) {
        if (students[i].ToFCriter(searchValue, searchType)) {
            students[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "No students found with the given criteria." << endl;
    }

    return 0;
}

